
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#include <Bitset>


int main()
{
	setlocale(LC_ALL, "Russian");
	int a = 260;
	int b = 0;
	bool c = true;
	char d = 'T';
	double e = 1.16354685;
	std::cout << std::fixed <<"При а=260 " << "a^4=" << pow(a, 4) <<'\n'		//Вывод a = 260 в 4 степени
		<< "          a^8=" << pow(a, 8) << '\n'		//Вывод a = 260 в 8 степени
		<< b << '\n'	//Вывод b = 0
		<< 'b' + 53 << '\n' //Вывод значения (Символа b = 98 в ASCII + 53)
		<< 37 + 'b' << '\n' //Вывод значения (37 + Символа b = 98 в ASCII)
		<< "Размер переменной int выражененой в байтах равен " << sizeof(int) <<'\n'	//Вывод размера переменной int выражененой в байтах
		<< '\n' << c << '\n'	//Вывод True(1)
		<< "Размер переменной bool выражененой в байтах равен " << sizeof(bool) << '\n'	//Вывод размера переменной bool выражененой в байтах
		<< '\n' << d <<'\n' //Вывод символа T
		<< "Размер переменной char выражененой в байтах равен " << sizeof(char) << '\n'	//Вывод размера переменной char выражененой в байтах
		<< std::endl;
	printf("%.10f", e*5); //Вывод числа e = 1.16354685 с плавающей точкой умноженной на 5
	std::cout << '\n' << "Размер переменной double выражененой в байтах равен " << sizeof(double) << std::endl;	//Вывод размера переменной double выражененой в байтах
	getchar();
    return 0;
}

