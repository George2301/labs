#pragma once
#include <iostream>

class Matrix{
private:
    int NMAX;
    int MMAX;
    double ** matrix;  
public:
    Matrix(int a = 0, int b = 0);
    void MatrixInput();
    ~Matrix();
    void MatrixBiggerElements(Matrix &m, double a = 0);
    void MatrixFromNumber(double a);
    double MAtrixAverage();
    void MatrixOutput();
};