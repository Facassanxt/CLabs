// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

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
	int arr[3][1] = { { 1 },
					  { 4,},
					  { 5,} };
	int arr1[3][1] = { { 1 },
					   { 3 },
					   { 2 } };
	int arr2[3][1] = { {} };
	int i,j = 0;

	for (i = 0; i < 3; i++)
	{
		arr2[i][j] = arr[i][j] * arr1[i][j];
		cout << arr2[i][j] << "\n";
	}
	getchar();
	return 0;
}