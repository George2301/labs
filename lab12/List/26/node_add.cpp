#include "node_add.h"

std::ostream& operator << (std::ostream& os, List_Exp& list){
    if (list.IsEmpty()){
        os << "NULL";
    } else {
        auto l = list.GetHead();
        while (list.GoForward(l) != NULL){
            os << list.GetVal(l) << " -> ";
            l = list.GoForward(l);
        }
        os << list.GetVal(l);
    }
    return os;
}


std::istream& operator >> (std::istream& in, List_Exp& list){
	int c;
	while (in >> c)
	{
		list.Push_back(c);
	}
	return in;
}

bool List_Exp::CheckNegative (){
  List<double>::node* head = GetHead();
  bool f = false;
  while (GoForward(head) && !f){
    if(GetVal(head) < 0)
      f = true;
    head = GoForward(head);  
  }
  return f;
}

void List_Exp::DeleteBigger (const double& a){
  List<double>::node *head = GetHead();
  if (abs(GetVal(head)) > a){
      Pop_first();
    }
  while (GoForward(head) && GoForward(GoForward(head))){
    if (abs(GetVal(GoForward(head))) > a){
      Pop_after(head);
    } else 
      head = GoForward(head);
  }
  if (GoForward(head))
    head = GoForward(head);
  if (abs(GetVal(head)) > a){
      Pop_back();
    }
  return;
}