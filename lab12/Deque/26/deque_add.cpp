#include "deque_add.h"

Deque_Exp::Deque_Exp(): Deque<char>() {
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

std::istream& operator>> (std::istream& in, Deque_Exp& de){
  char c;
  while(in >> c){
    de.Push_back(c);
  }
  return in;
}

bool CheckVowel(char c){
  return (c == 'A') || (c == 'a') || (c == 'E') || (c == 'e') || (c == 'I') || (c == 'i') || (c == 'O') || (c == 'o') || (c == 'Y') || (c == 'y');
}

void Deque_Exp::SeparateVowels(Deque_Exp& v, Deque_Exp& n){
  int c;
  while (GetLength() != 0){
    c = Front();
      if (CheckVowel(c)){
        TopToBottom(v);
      } else 
        TopToBottom(n);
  }
  return;
}