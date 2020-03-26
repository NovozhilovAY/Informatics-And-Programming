#pragma once
#include <iostream>
#include <locale>
#include <math.h>
#include <fstream>


class Matrix
{
private:
	int size;
	int** matrix;
public:
	Matrix();
	Matrix(int _size, int *m[]);
	Matrix(int _size);
	Matrix(const Matrix& m);
	~Matrix();

	Matrix& operator=(const Matrix& _matrix);
	Matrix operator+(const Matrix& _matrix)const;
	Matrix operator*(const Matrix& _matrix)const;
	Matrix operator*(const int& mult)const;
	int& operator()(int index1, int index2);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
	friend std::istream& operator>>(std::istream& os, Matrix& m);
	void Transp();
	void diagonal_p();
	void print();
};
