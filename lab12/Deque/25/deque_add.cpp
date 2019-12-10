#include "deque_add.h"

Deque_Exp::Deque_Exp(): Deque<int>() {
  return;
}

std::ostream& operator<< (std::ostream& os, Deque_Exp& de){
    if (de.GetLength() == 0){
        os << "NULL";
    } else {
        os << "{";
        for (int i = 0; i < de.GetLength() - 1; i++){
            os << de.GetD()[de.GetBefore() + i] << ", ";
        }
        os << de.GetD()[de.GetBefore() + de.GetLength() - 1] << "}";
    }
    os << " <=> ";
    if (de.GetLength() == 0){
        os << "NULL";
    } else {
        os << "{";
        for (int i = de.GetLength() - 1; i > 0; i--){
            os << de.GetD()[de.GetBefore() + i] << ", ";
        }
        os << de.GetD()[de.GetBefore()] << "}";
    }
    return os;
}

void Read(Deque_Exp& d, char *fname){
  std::ifstream in(fname);
  int c;
  while(in >> c){
    d.Push_back(c);
  }
  in.close();
  return;
}

bool CheckNumbers(int c){
  return !(c % 8);
}

void SeparateNumbers(Deque_Exp d, Deque_Exp& v, Deque_Exp& n){
  int c;
  while (d.GetLength() != 0){
    c = d.Front();
      if (CheckNumbers(c)){
        d.TopToBottom(v);
      } else 
        d.TopToBottom(n);
  }
  return;
}