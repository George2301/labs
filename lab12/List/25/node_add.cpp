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

bool List_Exp::CheckInRange (const int& a, const int& b){
  List<int>::node *head = GetHead();
  bool f = false;
  while (GoForward(head) && !f){
    head = GoForward(head);
    if(GetVal(head) >= a && GetVal(head) <= b)
      f = true;
  }
  return f;
}

void List_Exp::DeleteEven (){
  List<int>::node *head = GetHead();
  if (GetVal(head) % 2 == 0){
      Pop_first();
    }
  while (GoForward(head) && GoForward(GoForward(head))){
    if (GetVal(GoForward(head)) % 2 == 0){
      Pop_after(head);
    } else 
      head = GoForward(head);
  }
  if (GoForward(head))
    head = GoForward(head);
  if (GetVal(head) % 2 == 0){
      Pop_back();
    }
  return;
}