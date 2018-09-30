// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h" // в первую очередь искать рядом с проектом
#include <iostream> // угловые скобки <> - поиск файла в списке системных каталогов среды
#include <Windows.h>
#include <locale.h>

using namespace std;
/* ***************************
	ЛАБОРАТОРНАЯ РАБОТА 3
	МАССИВЫ И УКАЗАТЕЛИ
*************************** */

int main() // - обязательная точка входа в приложение
{
	// переменная, хранящая адрес каких то данных в ОП

	int a;
	a = 321;
	double dbl = 10.005;

	// 1. СИНТАКСИС УКАЗАТЕЛЯ
	// синтаксис объявления указателей "тип_данных * имя_указателя;"
	int * ptr_int;
	ptr_int = &a; //унарный оператор ампесенд & - оператор получения адреса
	double * ptr_dbl = &dbl;

	// все указатели всегда одной и той же разрядности (размера)
	// каким бы ни был огромным тип данных (строка, объект, массив)
	// указатель на него всегда будет всегда занимать 4/8 байт, что и является основным
	// преимуществом указателей std::cout << "int pointer size = " << sizeof(ptr_int) << std::endl;
	std::cout << "int pointer size = " << sizeof(ptr_int) << std::endl;
	std::cout << "double pointer size = " << sizeof(ptr_dbl) << std::endl;
	std::cout << "long long pointer size = " << sizeof(long long *) << std::endl;
	std::cout << "bool pointer size = " << sizeof(bool *) << std::endl;
	
	// в случае сборки на x64 размер указателей будет 8 байт (64 - разрядная адресация)
	// 2. РАЗМЕР УКАЗАТЕЛЯ
	
	std::cout << "ptr_int = " << ptr_int << std::endl;
	std::cout << "ptr_dbl = " << ptr_dbl << std::endl;

	// 3. СОДЕРЖИМОЕ УКАЗАТЕЛЕЙ
	
	// оператор разыменования указателей: чтобы получить значение,
	// хранящееся по данному указателю,
	// нужно еще раз применить оператор *
	int b = 0;
	b = a;
	b = *ptr_int; // получить обратно значение а, аналогично b = a
	std::cout << std::endl << "ptr_int = " << std::dec << *ptr_int << std::endl;
	std::cout << "* ptr_dbl = " << *ptr_dbl << std::endl;
	
	// 4. МАССИВ...

	int arr1D[10] = { 1, 50, 11, 12, 101 }; // одномерный массив из 10 целых знаковых чисел
	int arr2D[3][3] = { { 11, 12, 13 },
	{ 21, 22, 23 },
	{ 31, 32, 33 } }; // одномерный массив из 10 целых знаковых чисел

	for (int *i = &a - 50;
		i < &a + 50;
		i++)
	{
		std::cout <<
			"0x" << // шестнадцатиразрядные числа принято оформлять с 0x, особенно адреса ОП
			'\t' << //escape-символ кодирующий табуляцию
			i << //печатается содержимое указателя
			std::endl;
	}	// рядом печатается 0xадрес и значение

	// 5. УКАЗАТЕЛИ И МАССИВЫ

	// 5.1. просто имя массива без скобок имеет тип указателя,
	// имя двумерного массива имеет тип указатель на указатель
	// double arr1D[n] arr1D имеет тип (double*)
	// double arr2D[m][n] arr2D имеет тип (double**)
	// 5.2. обращаясь к arr2D[m], можно получить указатель на одномерный массив-строку
	// 5.3. оператор [] фактически прибавляет индекс к указателю массива: 
	// arr1D[i] то же самое, что и (arr1D + i)
	
	std::cout << "arr1D[3] = *(arr1D + 3) = "
	<< *(arr1D + 3) << std::endl;
	
	std::cout << "arr2D[2][2] = *(*(arr2D + 2) + 2) = "
	<< *(*(arr2D + 2) + 2) << std::endl;
	
	
	
	
	getchar();
	return 0;

}