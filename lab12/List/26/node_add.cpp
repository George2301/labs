#include "node_add.h"

List_Exp::List_Exp(): List<double>(){   
    return;
}

std::ostream& operator<< (std::ostream& os, List_Exp& list){
    node<double> *l = list.GetHead();
    if (l == NULL){
        os << "NULL";
    } else {
        while (list.GoForward(l) != NULL){
            os << list.GetVal(l) << " -> ";
            l = list.GoForward(l);
        }
        os << list.GetVal(l);
    }
    return os;
}

void Read(List_Exp& l, double& a, char *fname){
  std::ifstream in(fname);
  in >> a;
  int c;
  while(in >> c){
    l.Push_back(c);
  }
  in.close();
  return;
}

bool CheckNegative (List_Exp& list){
  node<double> *head = list.GetHead();
  bool f = false;
  while (list.GoForward(head) && !f){
    if(list.GetVal(head) < 0)
      f = true;
    head = list.GoForward(head);  
  }
  return f;
}

void DeleteBigger (List_Exp& list, const double& a){
  node<double> *head = list.GetHead();
  if (abs(list.GetVal(head)) > a){
      list.Pop_first();
    }
  while (list.GoForward(head) && list.GoForward(list.GoForward(head))){
    if (abs(list.GetVal(list.GoForward(head))) > a){
      list.Pop_after(head);
    } else 
      head = list.GoForward(head);
  }
  if (list.GoForward(head))
    head = list.GoForward(head);
  if (abs(list.GetVal(head)) > a){
      list.Pop_back();
    }
  return;
}