#include "deque_add.h"

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

std::istream& operator>> (std::istream& in, Deque_Exp& de){
  int c;
  while(in >> c){
    de.Push_back(c);
  }
  return in;
}


bool CheckNumbers(int c){
  return !(c % 8);
}

void Deque_Exp::SeparateNumbers(Deque_Exp& v, Deque_Exp& n){
  int c;
  while (GetLength() != 0){
    c = Front();
      if (CheckNumbers(c)){
        TopToBottom(v);
      } else 
        TopToBottom(n);
  }
  return;
}