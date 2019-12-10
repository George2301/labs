#include "node_add.h"

List_Exp::List_Exp(): List<int>(){   
    return;
}

std::ostream& operator<< (std::ostream& os, List_Exp& list){
    node<int> *l = list.GetHead();
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

void Read(List_Exp& l, int& a, int& b, char *fname){
  std::ifstream in;
  in.open(fname);
  in >> a >> b;
  int c;
  while(in >> c){
    l.Push_back(c);
  }
  in.close();
  return;
}

bool CheckInRange (List_Exp& list, const int& a, const int& b){
  node<int> *head = list.GetHead();
  bool f = false;
  while (list.GoForward(head) && !f){
    head = list.GoForward(head);
    if(list.GetVal(head) >= a && list.GetVal(head) <= b)
      f = true;
  }
  return f;
}

void DeleteEven (List_Exp& list){
  node<int> *head = list.GetHead();
  if (list.GetVal(head) % 2 == 0){
      list.Pop_first();
    }
  while (list.GoForward(head) && list.GoForward(list.GoForward(head))){
    if (list.GetVal(list.GoForward(head)) % 2 == 0){
      list.Pop_after(head);
    } else 
      head = list.GoForward(head);
  }
  if (list.GoForward(head))
    head = list.GoForward(head);
  if (list.GetVal(head) % 2 == 0){
      list.Pop_back();
    }
  return;
}