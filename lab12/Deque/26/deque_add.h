#pragma once
#include <iostream>
#include <fstream>
#include "deque.h"

class Deque_Exp : public Deque<char>{
private:

public:
  Deque_Exp();
  friend std::ostream& operator<< (std::ostream& os, Deque_Exp& d);
  friend void Read(Deque_Exp& d, char *fname);
  friend bool CheckVowel(char c);
  friend void SeparateVowels(Deque_Exp d, Deque_Exp& v, Deque_Exp& n);
};
