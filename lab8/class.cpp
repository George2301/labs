#pragma once
#include "class.h"
#include <iostream>

Matrix::Matrix(int a, int b){
    if (a >= 0 && b >= 0){
        NMAX = a;
        MMAX = b;
        matrix = new double* [a];
            for (int i = 0; i < this->NMAX; i++){
                this->matrix[i] = new double[b];
                for (int j = 0; j < this->MMAX; j++)
                    this->matrix[i][j] = 0;
            }
    }
    return;
}

Matrix::~Matrix(){
    for(int i = 0; i < NMAX; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    return;
}

void Matrix::MatrixBiggerElements(Matrix &m, double a){
    m.NMAX = NMAX;
    m.MMAX = MMAX;
    double **k = new double* [NMAX];
    for (int i = 0; i < NMAX; ++i){
        k[i] = new double [MMAX];
        for (int j = 0; j < MMAX; ++j)
            k[i][j] = matrix[i][j] + a;
        }
    m.matrix = k;

    return;
}

void Matrix::MatrixFromNumber(double a){
    Matrix();
    matrix = new double* [1];
    matrix[0] = new double [1];
    matrix[0][0] = a;
    NMAX = 1; MMAX = 1;
    return;
}

double Matrix::MAtrixAverage(){
    double a = 0;
    for (int i = 0; i < NMAX; i++){
        for (int j = 0; j < NMAX; j++){
            a += matrix[i][j];
        }
    }
    a = a / (NMAX * MMAX);
    return a;
}

void Matrix::MatrixInput(){
    for (int i = 0; i < NMAX; i++){
        for (int j = 0; j < NMAX; j++){
            //scanf("%lf", &matrix[i][j]);
            std::cin >> matrix[i][j];
        }
    }
    return;
}

void Matrix::MatrixOutput(){
    for (int i = 0; i < NMAX; i++){
        for (int j = 0; j < NMAX; j++){
            //printf("%6.2f ", matrix[i][j]);
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return;
}
