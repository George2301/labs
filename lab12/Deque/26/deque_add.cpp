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

void Read(Deque_Exp& d, char *fname){
  std::ifstream in(fname);
  char c;
  while(in >> c){
    d.Push_back(c);
  }
  in.close();
  return;
}

bool CheckVowel(char c){
  return (c == 'A') || (c == 'a') || (c == 'E') || (c == 'e') || (c == 'I') || (c == 'i') || (c == 'O') || (c == 'o') || (c == 'Y') || (c == 'y');
}

void SeparateVowels(Deque_Exp d, Deque_Exp& v, Deque_Exp& n){
  int c;
  while (d.GetLength() != 0){
    c = d.Front();
      if (CheckVowel(c)){
        d.TopToBottom(v);
      } else 
        d.TopToBottom(n);
  }
  return;
}