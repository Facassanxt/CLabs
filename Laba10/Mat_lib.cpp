#include "stdafx.h"
#include "Mat_lib.h"
#include <iostream>
using namespace std;


matrix::matrix() {}

matrix::matrix(unsigned int rows, unsigned int cols)
{
	m = rows; n = cols;
	mat = new double*[m];
	for (int i = 0; i < m; i++)
		mat[i] = new double[n];
}
matrix::~matrix() {}

void matrix::set() // Заполение
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Vvedite [" << i << "][" << j << "] element matrix: ";
			cin >> mat[i][j];
		}
	}
	cout << endl;
}

void matrix::print() // Вывод
{
	cout << "\n Print:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << " " << mat[i][j] << " ";
		}
		cout << endl;
	}
}

matrix operator+(const matrix &ob1, const matrix &ob2) // Перегрузка оператора + 
{
	matrix с(ob1.m, ob2.n);
	for (int i = 0; i < ob1.m; i++)
	{
		for (int j = 0; j < ob2.n; j++)
		{
			с.mat[i][j] = ob1.mat[i][j] + ob2.mat[i][j];
		}
	}
	return(с);
}

matrix operator*(const matrix &ob1, const matrix &ob2) // Перегрузка оператора * 
{
	matrix z(ob1.m, ob2.n);
	for (int i = 0; i < ob1.m; i++)
	{
		for (int j = 0; j < ob2.n; j++)
		{
			z.mat[i][j] = ob1.mat[i][j] * ob2.mat[i][j];
		}
	}
	return(z);
}

matrix matrix::operator+=(const matrix &ob) // Перегрузка оператора += 
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < ob.n; j++)
		{
			this->mat[i][j] = mat[i][j] + ob.mat[i][j];
		}
	}
	return (*this);
}

matrix matrix::operator*=(const matrix &ob) //  Перегрузка оператора *=
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < ob.n; j++)
		{
			for (int k = 0; k < n; k++)
			{

				this->mat[i][j] = mat[i][j] * ob.mat[i][j];

			}
		}
	}
	return (*this);
}