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
	int arr[3][3] = { { 1,2,3 },{ 4,5,6 },{ 5,4,3 } };
	int arr1[3][3] = { { 0,1,3 },{ 3,2,1 },{ 0,3,1 } };
	int arr2[3][3] = { {} };
	int i, k , j;

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
	getchar();
	return 0;
}