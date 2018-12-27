#include <fstream> 
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#include <Bitset>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <tuple>
#include <list>
using namespace std;
// Класс контейнер - обобщенная разновидность библиотечных классов инкапсулирующая набор однотипных данных, чаще всего массив и обеспечивающего его необходимым функционалом (вствка, сортировка и т.п)
// Класс поток - класс реализующий логику потокового (последовательного) ввода, вывода ( в файл, в сетевой сокет, в буфер, в порт, на экран) 
// А такэе дополнительные удобства: автоматическое отслеживание позицей ввода и вывода, отслеживание объема данных, привидение типов и т.п




// Шаблон - средство автоматизации создания исходного кода, при котором процессор сам дописывает исходный код подставляя типы и значение
// Шаблоны могут назначатся для классов и функций 
// Для преобращение класса в шаблон необходимо:
// 1) Задать нужные константы и классы индификаторами
// 2) Дописать перед объявлением класса или конструкциеей template с перечислением используемых индификаторах в угловых скобках
// Шаблон работает на уровне

// Вместо использования шаблона приходилось бы переобъявлять практически один и тот же класс с небольшими изминениями

// template <class C, type name T, int n1, double d1>
//	class class_1{ T data[n1]; C subclass; double d=d1 }
//



// шаблон функции printArray
template <typename T>
void printArray(const T * array, int count)
{
	for (int ix = 0; ix < count; ix++)
		cout << array[ix] << "   ";
	cout << endl;
} // конец шаблона функции printArray
int main()
{
	setlocale(LC_ALL, "rus");
	// размеры массивов
	const int iSize = 10,
		dSize = 7,
		fSize = 10,
		cSize = 5;
	// массивы разных типов данных
	int    iArray[iSize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double dArray[dSize] = { 1.2345, 2.234, 3.57, 4.67876, 5.346, 6.1545, 7.7682 };
	float  fArray[fSize] = { 1.34, 2.37, 3.23, 4.8, 5.879, 6.345, 73.434, 8.82, 9.33, 10.4 };
	char   cArray[cSize] = { "MARS" };
	cout << "\t\t Шаблон функции вывода массива на экран\n\n";
	// вызов локальной версии функции printArray для типа int через шаблон
	cout << "\nМассив типа int:\n"; printArray(iArray, iSize);
	// вызов локальной версии функции printArray для типа double через шаблон
	cout << "\nМассив типа double:\n"; printArray(dArray, dSize);
	// вызов локальной версии функции printArray для типа float через шаблон
	cout << "\nМассив типа float:\n"; printArray(fArray, fSize);
	// вызов локальной версии функции printArray для типа char через шаблон
	cout << "\nМассив типа char:\n"; printArray(cArray, cSize);

	system("Pause");
	return 0;
}