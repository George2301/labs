#pragma once
#include <iostream>
#include <fstream>
#include "node.h"

class List_Exp : public List<int>{
public:
  friend std::ostream& operator << (std::ostream& os, List_Exp& list);
  friend std::istream& operator >> (std::istream& in, List_Exp& list);
  bool CheckInRange (const int& a, const int& b);
  void DeleteEven ();
};

