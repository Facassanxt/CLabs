// определяет точку входа для консольного приложения.
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
	int * ptr_int;
	double * ptr_dbl;
	cout
		<< "int pointer size = " << sizeof(ptr_int) << "\n"
		<< "double pointer size = " << sizeof(ptr_dbl) << "\n"
		<< "char pointer size = " << sizeof(char *) << "\n"
		<< "long long pointer size = " << sizeof(long long *) << "\n"
		<< "bool pointer size = " << sizeof(bool *) << "\n" 
	<<endl;

	getchar();
	return 0;
}

