
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#include <Bitset>
using namespace std;
/*
class Matrix
{
private:
	double ** data,p;
	unsigned int n, m;
public:
	Matrix();
		Matrix(unsigned int m, unsigned int n);
		Matrix(double ** data, unsigned int m, unsigned int n);
		void mul(double ** data, unsigned int m, unsigned int n)
		{
			m = 3;
			n = 3;
			p = new double*[m];
			for (int i = 0; i < m; i++)
				p[i] = new double*[n];
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cin >> p[i][j];
				}
			}
		}

		int arr[3][3] = { { 1,2,3 },
		{ 4,5,6 },
		{ 5,4,3 } };
		int arr1[3][3] = { { 0,1,3 },
		{ 3,2,1 },
		{ 0,3,1 } };
		int arr2[3][3] = { { 0 } };
		int sum = 0, i, k = 0, j = 0;
	
	void emul();
	void sum ();

	void print();
	~Matrix();
};*/

/*class Auto 
{
private:
	int year, month, day;
public:
	Auto()
	{
		year = 2000;
		month = 12;
		day = 31;
		get();
		cout << endl;
	}
	Auto(int date_year, int date_month, int date_day)
	{
	year = date_year;
	month = date_month;
	day = date_day;
	}
	
	void message()
	{
		cout << "Class is working!" << endl;
	}
	void set(int date_year, int date_month, int date_day)
	{
		year = date_year;
		month = date_month;
		day = date_day;
	}
	void get()
	{
		cout << "Year of this auto is - " << year
			<< ", month is - " << month
			<< ", day is - " << day << endl;
	}
	~Auto()
	{
	 cout << "Class is not working" << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	Auto shkoda(2015, 2, 13;
	shkoda.message();
	shkoda.set(2005, 11, 23);
	shkoda.get();

	Matrix bmw;
	bmw.set(2012, 1, 11);
	bmw.get();



	system("pause");
	return 0;
}
*/
/*
class Matrix
{
private:
	int arr[3][3] = { { 1,2,3 },
	{ 4,5,6 },
	{ 5,4,3 } };
	int arr1[3][3] = { { 0,1,3 },
	{ 3,2,1 },
	{ 0,3,1 } };
	int arr3[3][1] = { { 1 },
	{ 3 },
	{ 2 } };
	int a[3] = { { 1 },{ 2 },{ 3 } };
	int b[3] = { { 3 },{ 2 },{ 1 } };
public:
	int arr2[3][3] = { { 0 } };
	int arr4[3][1] = { {} };
	int sum = 0, i = 0, k = 0, j = 0;
	
	void emul()
	{
		cout << "Поэлементное умножение \n";
		for (i; i <= 2; i++)
		{
			for (k; k <= 2; k++)
			{
				arr2[i][k] = arr[i][k] * arr1[i][k]; // Поэлементное умножение
				cout << arr2[i][k] << " "; // Вывод матрицы
				arr2[i][k] = 0; // Зануление матрицы
			}
			k = 0;
			cout << '\n';
		}
	}
	void mul()
	{
		cout << "\nУмножение матриц \n";
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				for (k = 0; k < 3; k++)
				{
					arr2[i][j] += arr[i][k] * arr1[k][j];
				}
				cout << arr2[i][j] << "  ";
			}
			cout << "\n";
		}
	}
	void mulvec()
	{
		cout << "\nУмножение матриц на вектор \n";
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 1; j++)
			{
				for (k = 0; k < 3; k++)
				{
					arr4[i][j] += arr[i][k] * arr3[k][j];
				}
				cout << arr4[i][j] << "  ";
			}
			cout << "\n";
		}
	}
	void skalprod()
	{
		cout << "\nСкалярное произведение \n";
		for (int i = 0; i < 3; i++)
		{
			sum += a[i] * b[i];
		}
		cout << sum << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Matrix el;
	el.emul();
	el.mul();
	el.mulvec();
	el.skalprod();


	system("pause");
	return 0;
}
*/
	int main()
	{
		setlocale(LC_ALL, "Russian");
		int rows, cols;
		cout << "Введите x и y: " << endl;
		cin >> rows >> cols;
		rows = rows;
		cols = cols;
		int **ar = new int*[rows];

		for (int i = 0; i < rows; i++)
		{
			ar[i] = new int[cols];
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << "Ввод " << "[" << i + 1 << "]" << "[" << j + 1 << "]" << " ";
				cin >> ar[i][j];
			}
		}


		cout << "\n Ответ:\n";
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << " " << ar[i][j] << " ";
			}
			cout << endl;
		}

		system("Pause");
		return 0;
	}