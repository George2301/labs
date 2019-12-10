#pragma once
#include <iostream>
#include <fstream>
#include "deque.h"

class Deque_Exp : public Deque<int>{
private:
  //int*d;
  //int before, after, length;
public:
  Deque_Exp();
  friend std::ostream& operator<< (std::ostream& os, Deque_Exp& d);
  friend void Read(Deque_Exp& d, char *fname);
  friend bool CheckNumbers(int c);
  friend void SeparateNumbers(Deque_Exp d, Deque_Exp& v, Deque_Exp& n);
};
