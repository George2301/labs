#pragma once
#include <iostream>
#include <fstream>
#include "node.h"

class List_Exp : public List<int>{
private:
  node<int> *head;
public:
  List_Exp();
  friend std::ostream& operator<< (std::ostream& os, List_Exp& list);
  friend void Read(List_Exp& l, int& a, int& b, char *fname);
  friend bool CheckInRange (List_Exp& list, const int& a, const int& b);
  friend void DeleteEven (List_Exp& list);
};

