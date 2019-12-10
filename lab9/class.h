#pragma once
#include <iostream>

class Matrix{
private:
    int NMAX;
    int MMAX;
    double ** matrix; 

    class Line{
    private:
        double *line;
        int Ncolls;
    public:
        Line(double* line, int Ncolls);
        double& operator [] (int n);
    };

public:
    Matrix(int a = 0, int b = 0);
    void MatrixInput();
    ~Matrix();
    void MatrixBiggerElements(Matrix &m, double a = 0);
    void MatrixFromNumber(double a);
    double MAtrixAverage();
    void MatrixOutput();

    Matrix& operator = (const Matrix& a);
    bool operator == (const Matrix& a);
    bool operator != (const Matrix& a);
    Line operator [] (int m);
    Matrix& operator + (const Matrix& a);
    Matrix& operator - (const Matrix& a);
    Matrix& operator += (const Matrix& a);
};