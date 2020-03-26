#include "Matrix.h"

Matrix::Matrix()
{
	size = 5;
	matrix = new int*[size];
	for (int i= 0; i < size; i++)
	{
		matrix[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(int _size, int *m[])
{
	size = _size;
	matrix = new int*[size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
	}
	for (int j = 0; j < size; j++)
	{
		for (int k = 0; k < size; k++)
		{
			matrix[j][k] = m[j][k];
		}
	}
}

Matrix::Matrix(int _size)
{
	size = _size;
	matrix = new int*[size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = rand()%10;
		}
	}
}

Matrix::Matrix(const Matrix & m)
{
	size = m.size;
	matrix = new int*[size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = 0;
	size = 0;
}

Matrix & Matrix::operator=(const Matrix & _matrix)
{
	if (size != _matrix.size)
	{
		
		for (int i = 0; i < size; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		matrix = new int*[_matrix.size];
		size = _matrix.size;
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new int[size];
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = _matrix.matrix[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix & _matrix) const
{
	if (size != _matrix.size)
	{
		throw "Ќельз€ складывать матрицы разного размера!!!\n";
	}
	else
	{
		Matrix m(size);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				m.matrix[i][j] = matrix[i][j] + _matrix.matrix[i][j];
			}
		}
		return m;
	}
}

Matrix Matrix::operator*(const Matrix & _matrix) const
{
	if (size != _matrix.size)
	{
		throw "ћатрицы умножить нальз€!!!\n";
	}
	else
	{
		Matrix m(size);
		for (int i = 0; i < size; i++) 
		{           
			for (int j = 0; j < size; j++)
			{
				m.matrix[i][j] = 0;
				for (int t = 0; t < size; t++)
				{
					m.matrix[i][j] += matrix[i][t] * _matrix.matrix[t][j];
				}
			}
		}
		return m;
	}
}


Matrix Matrix::operator*(const int & mult) const
{
	Matrix m(*this);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			m.matrix[i][j] *= mult;
		}
	}
	return m;
}

int& Matrix::operator()(int index1, int index2)
{
	if (index1 >= size || index1 < 0 || index2 >= size || index2 < 0)
	{
		throw "¬ыход за границу массива!";
	}
	return matrix[index1][index2];
}

void Matrix::Transp()
{
	int tmp;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			tmp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}
	}
}

void Matrix::diagonal_p()
{
	int s = 0;
	int de;
	for (int i = 0; i < size; i++)
	{
		de = abs(matrix[i][i]);
		for (int j = 0; j < size; j++)
		{
			s += abs(matrix[i][j]);
		}
		if (de <= s - de)
		{
			std::cout << "ћатрица не обладает диагональным преобладанием" << std::endl;
			return;
		}
		s = 0;
	}
	std::cout << "ћатрица обладает диагональным преобладанием" << std::endl;
}

void Matrix::print()
{
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Matrix & m)
{
	os << m.size << std::endl;
	for (int i = 0; i < m.size; i++)
	{
		for (int j = 0; j < m.size; j++)
		{
			os << m.matrix[i][j] << "\t";
		}
		os << std::endl;
	}
	return os;
}

std::istream & operator>>(std::istream & is, Matrix & m)
{

	for (int i = 0; i < m.size; i++)
	{
		delete[] m.matrix[i];
	}
	delete[] m.matrix; 
	is >> m.size;
	m.matrix = new int*[m.size];
	for (int i = 0; i < m.size; i++)
	{
		m.matrix[i] = new int[m.size];
	}
	
	for (int i = 0; i < m.size; i++)
	{
		for (int j = 0; j < m.size; j++)
		{
			is >> m.matrix[i][j];
		}
		
	}
	return is;
}
