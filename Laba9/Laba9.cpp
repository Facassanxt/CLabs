// Laba9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#include <Bitset>
using namespace std;
// ПЕРЕГРУЗКА ФУНКЦИЙ, МЕТОДОВ И ОПЕРАТОРОВ
// Перегрузка (overloading) - объявление нескольких функций (а также методов классов и операторов
// является функциями) с одинаковыми именами, но разным набором аргументов.

// 1.СИНТАКСИС. Просто объявление рядом нескольких функций с идентичными именами.
// Входные параметры обязательно должны различаться.
// Различные по выходному параметру не являются перегрузко.
// Когда компилятор встречает в тексте программу вызов одной из перегруженных функций
// он подставляет одну из них, ориентируясь на список переданных параметров, как на сигнатуру
// В отличие от Pascal дополнительные служебные слова не требуются

// 2. ПРИМЕРЫ ИСПОЛЬЗОВАНИЯ
// Математические функции для float и для double
// Строковые методы для Std::string и для char*
// Перегрузка конструкторов (пустой и копирующий конструктор

// 3. ПЕРЕГРУЗКА ОПЕРАТОРОВ
// Операторы в С++ являются функциями, и их можно перегружать
// Унарные и бинарные операторы перегружаются по-разному (Солтер "С++ для профессионалов)
// Унарные операторы перегружаются как метод пользовательского класса
// а бинарные - как отдельные функции

/*
class matr
{
public:
matr() {};
matr(const matr & p1) {};
dauble data[3][3] = { 0 };
size_t columns = 3;
size_t rows = 3;
mat & operator ++()
{

}
*/

mat operator + (const mat & lhs, // left hand side
	const mat & rhs) // right hand side
{
	mat result
}

// ОПЕРАТОР THIS

int main() // !!! ФУНКЦИЯ MAIN НЕ МОЖЕТ БЫТЬ ПЕРЕГРУЖЕННА
{
	string str3, str2, str1;
	char abc[255];
	str1.at(1);
	string * str2;
	str2 = new string();
	str2->at(1);


	str1 = str2 + abc;
	str3 = str2 + str1;
	mat3 = mat1 + mat2;
	mat3.some_add_function(mat1, mat2); //Унарный  (тоже самое что и перед ним)
	system("pause");
    return 0;
}
// ДЗ: Реализовать умножение

