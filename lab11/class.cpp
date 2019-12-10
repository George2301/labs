#include "class.h"
#include <iostream>

Matrix::Matrix(int a, int b){
    if (a >= 0 && b >= 0){    
    MMAX = b;
	NMAX = a;
	this->MatrixIinit();
	this->MatrixZeros();
    } else throw Exception(1);
	return;
}

void Matrix::MatrixZeros() {
	for (int i = 0; i < NMAX; i++)
		for (int j = 0; j < MMAX; j++)
			matrix[i][j] = 0;
	return;
}

void Matrix::MatrixIinit() {
	matrix = new double*[NMAX];
	for (int i = 0; i < NMAX; i++)
		matrix[i] = new double[MMAX];
	return;
}

Matrix::~Matrix(){
    for(int i = 0; i < this->NMAX - 1; i++){
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
    this->MatrixIinit();
	this->MatrixZeros();
	for (int i = 0; i < NMAX; i++) {
		for (int j = 0; j < MMAX; j++) {
			this->matrix[i][j] = a.matrix[i][j];
		}
	}
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

Matrix Matrix::operator + (const Matrix& a){
    Matrix result(a.NMAX, a.MMAX);
	if (this->NMAX == a.NMAX && this->MMAX == a.MMAX) {
		for (int i = 0; i < a.NMAX; i++) {
			for (int j = 0; j < a.MMAX; j++) {
				result.matrix[i][j] = this->matrix[i][j] + a.matrix[i][j];
			}
		}
	} else throw Exception(2);
	return result;
}

Matrix Matrix::operator - (const Matrix& a){
    Matrix result(a.NMAX, a.MMAX);
	if (this->NMAX == a.NMAX && this->MMAX == a.MMAX) {
		for (int i = 0; i < a.NMAX; i++) {
			for (int j = 0; j < a.MMAX; j++) {
				result.matrix[i][j] = this->matrix[i][j] - a.matrix[i][j];
			}
		}
	} else throw Exception(2);
	return result;
}

Matrix& Matrix::operator += (const double& a){
        for (int i = 0; i < this->NMAX; i++)
            for (int j = 0; j < this->NMAX; j++)
                this->matrix[i][j] = this->matrix[i][j] + a;
    return *this;
}

Matrix::Line::Line(double* line, int Ncolls){
    this->line = line;
    this->Ncolls = Ncolls;
    return;
}

double& Matrix::Line::operator [] (int m){
    if (m >= 0 && m < Ncolls)
        return line[m];
    else throw Exception(1);
}

Matrix::Line Matrix::operator [] (int n){
    if (n >= 0 && n < NMAX)
        return Line(this->matrix[n], MMAX);
    else throw Exception(1);
}

Matrix MatrixSum(const Matrix& m1, const Matrix& m2) {
	Matrix result(m1.NMAX, m1.MMAX);
	if (m1.NMAX == m2.NMAX && m1.MMAX == m2.MMAX) {
		for (int i = 0; i < m1.NMAX; i++) {
			for (int j = 0; j < m1.MMAX; j++) {
				result.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
			}
		}
	} else throw Exception(2);
	return result;
}

Matrix MatrixDiffer(const Matrix& m1, const Matrix& m2) {
	Matrix result(m1.NMAX, m1.MMAX);
	if (m1.NMAX == m2.NMAX && m1.MMAX == m2.MMAX) {
		for (int i = 0; i < m1.NMAX; i++) {
			for (int j = 0; j < m1.MMAX; j++) {
				result.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
			}
		}
	} else throw Exception(2);
	return result;
}

Exception::Exception(int error){
        if (error == 1) ex = "INDEX_OUT_OF_RANGE ";
        if (error == 2) ex = "DIFFERENT_SIZE_MATRICES";
}

char* Exception::getError() const{
        return ex;
}