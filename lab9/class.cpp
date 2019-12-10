#pragma once
#include "class.h"
#include <iostream>

Matrix::Matrix(int a, int b){
    if (a >= 0 && b >= 0){
        this->NMAX = a;
        this->MMAX = b;
        this->matrix = new double* [a];
            for (int i = 0; i < this->NMAX; i++){
                this->matrix[i] = new double[b];
                for (int j = 0; j < this->MMAX; j++)
                    this->matrix[i][j] = 0;
            }
    }
    return;
}

Matrix::~Matrix(){
    for(int i = 0; i < this->NMAX; i++){
        delete[] this->matrix[i];
    }
    delete[] this->matrix;
    return;
}

void Matrix::MatrixBiggerElements(Matrix &m, double a){
    m.NMAX = this->NMAX;
    m.MMAX = this->MMAX;
    double **k = new double* [this->NMAX];
    for (int i = 0; i < this->NMAX; ++i){
        k[i] = new double [this->MMAX];
        for (int j = 0; j < this->MMAX; ++j)
            k[i][j] = this->matrix[i][j] + a;
        }
    m.matrix = k;

    return;
}

void Matrix::MatrixFromNumber(double a){
    Matrix();
    this->matrix = new double* [1];
    this->matrix[0] = new double [1];
    this->matrix[0][0] = a;
    this->NMAX = 1; this->MMAX = 1;
    return;
}

double Matrix::MAtrixAverage(){
    double a = 0;
    for (int i = 0; i < this->NMAX; i++){
        for (int j = 0; j < this->NMAX; j++){
            a += this->matrix[i][j];
        }
    }
    a = a / (this->NMAX * this->MMAX);
    return a;
}

void Matrix::MatrixInput(){
    for (int i = 0; i < this->NMAX; i++){
        for (int j = 0; j < this->NMAX; j++){
            std::cin >> this->matrix[i][j];
        }
    }
    return;
}

void Matrix::MatrixOutput(){
    for (int i = 0; i < this->NMAX; i++){
        for (int j = 0; j < this->NMAX; j++){
            std::cout << this->matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return;
}

Matrix& Matrix::operator = (const Matrix& a){
    this->NMAX = a.NMAX;
    this->MMAX = a.MMAX;
    this->matrix = a.matrix;
    return *this;
}

bool Matrix::operator == (const Matrix& a){
    bool f = (a.NMAX == this->NMAX);
    f = f && (a.MMAX == this->MMAX);
    int i = 0;
    int j = 0;
    while (f && i < NMAX && j < NMAX){
        f = f && (this->matrix[i][j] == a.matrix[i][j]);
        ++i;
        ++j;
    } 
    return f;
}

bool Matrix::operator != (const Matrix& a){
    return !(*this == a);
}

Matrix& Matrix::operator + (const Matrix& a){
    Matrix m = a;
    if(this->NMAX == a.NMAX && this->MMAX == a.MMAX){
        m.NMAX = this->NMAX;
        m.MMAX = this->MMAX;
        for (int i = 0; i < this->NMAX; i++)
            for (int j = 0; j < this->MMAX; j++)
                this->matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];
    }
    return *this;
}

Matrix& Matrix::operator - (const Matrix& a){
    Matrix m = a;
    if(this->NMAX == a.NMAX && this->MMAX == a.MMAX){
        m.NMAX = this->NMAX;
        m.MMAX = this->MMAX;
        for (int i = 0; i < this->NMAX; i++)
            for (int j = 0; j < this->NMAX; j++)
                m.matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
    }
    return m;
}

Matrix& Matrix::operator += (const Matrix& a){
        this->NMAX = a.NMAX;
        this->NMAX = a.NMAX;
        for (int i = 0; i < this->NMAX; i++)
            for (int j = 0; j < this->NMAX; j++)
                this->matrix[i][j] = this->matrix[i][j] + a.matrix[i][j];
    return *this;
}

Matrix::Line::Line(double* line, int Ncolls){
    this->line = line;
    this->Ncolls = Ncolls;
    return;
}

double& Matrix::Line::operator [] (int n){
    if (n >= 0 && n <= Ncolls)
        return line[n];
}

Matrix::Line Matrix::operator [] (int m){
    if (m >= 0 && m <= NMAX)
        return Line(this->matrix[m], MMAX);
}