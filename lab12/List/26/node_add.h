#pragma once
#include <iostream>
#include <fstream>
#include "node.h"

class List_Exp : public List<double>{
private:
  node<double> *head;
public:
  List_Exp();
  friend std::ostream& operator<< (std::ostream& os, List_Exp& list);
  friend void Read(List_Exp& l, double& a, char *fname);
  friend bool CheckNegative (List_Exp& list);
  friend void DeleteBigger (List_Exp& list, const double& a);
};

