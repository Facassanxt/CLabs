
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#include <Bitset>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int arr[3][3] = { { 1,2,3 },
					  { 4,5,6 },
					  { 5,4,3 } };
	int arr1[3][3] = { { 0,1,3 },
					   { 3,2,1 },
					   { 0,3,1 } };
	int arr2[3][3] = { { 0 } };
	int sum = 0, i, k = 0, j = 0;

	cout << "Поэлементное умножение \n";

	for (i = 0; i <= 2; i++)
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

	cout << "\nУмножение матриц на вектор \n";

	int arr3[3][1] = { { 1 },
					   { 3 },
					   { 2 } };
	int arr4[3][1] = { {} };

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

	cout << "\nСкалярное произведение \n";


	int a[3] = { { 1 },{ 2 },{ 3 } };
	int b[3] = { { 3 },{ 2 },{ 1 } };
	int En = 0;
	for (int i = 0; i < 3; i++)
	{
		En += a[i] * b[i];
	}
	cout << En << endl;


	getchar();
	return 0;
}

