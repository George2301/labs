#pragma once
#include <iostream>
#include <fstream>
#include "deque.h"

class Deque_Exp : public Deque<char>{
private:

public:
  Deque_Exp();
  friend std::ostream& operator<< (std::ostream& os, Deque_Exp& d);
  friend std::istream& operator>> (std::istream& in, Deque_Exp& de);
  void SeparateVowels(Deque_Exp& v, Deque_Exp& n);
};

bool CheckVowel(char c);