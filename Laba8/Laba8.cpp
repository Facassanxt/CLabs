#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#include <Bitset>
using namespace std;

// 1.СТРОКИ И ФАЙЛЫ
//	СТРОКИ СТАРОГО С-типа
// представляют из себя всего лишь массив символов с нулевым окончанием:
// по нулю определяется конец строки. В случае, если пользователь забыл поставить 0
// или он по тем или иным причинам стерся, функции С будут пытаться считывать символы до тех пор,
// пока не встреят 0 или не вызовут ошибку
char cstr1[] = "C - style_string1"; // '0' в конце дописывается автоматически
char cstr2[] = { 'C','-', '2','\0'};
// 2. ФУНЦИИ ДЛЯ РАБОТЫ С С-строками
// вывод на печать print(char*, , , ) или printf_s(char*, , , ) - print formatted
//% f - параметр подставляется на место% f, оформленное в виде числа с плавающей точкой 
//% s - параметр подставляется на место% s как строка 
//% d - параметр подставляется на место% d как целое число 
//% e - параметр подставляется на место% e как число в экспоненциальном виде

// 3. ПРОЧИЕ СТРОКОВЫЕ ФУНКЦИИ 
// объединение (конкатенация) строк strcat (* char, * char) 
// копирование из одной строки в другую strcpy () 
// сравнение strcmp () , если строки идентичны, возвращает 0, иначе - позиция первого различается
// длина строки strlen () 
// чтение с консоли scanf(*char, параметр)
// вставка строки в строке производится в несколько действий

// 4. СТРОКА С ++ 
// в стандартном библиотеке C ++ массивный текст инкапсулирован в КЛАСС std :: string 
// в который также собраны самые часто используемые методы обработки 
// (конкатенация, подсчет длины, вставка, удаление, поиск и т. д.)
// и для которого перегружены операторы + (конкатенация), ввод, вывод и т.д. 
// ещё одно отличие от строк C - длина строк теперь задаётся отедельным числом, 
// хранится в классе, а не нулевым окончанием
// Примеры: 
// std :: string cppstr1 = "C ++ - строка стиля 1"; 
// std :: string cppstr2 = "";

// 5.РАБОТА С ФАЙЛАМИ С++
// Класс fstream - поток ввода/вывода
// аналогичен cin и cout, но не на консоль, а в файл
// необходим #include <fstream>
// цикл работы с файлом:
//1) указать имя открыть для чтения/записи
//2) перейти на нужную позицию
//3) прочитать или записать
//4) закрыть файл
int main()
{
	char w[] = "2";
	char ws[] = "g";

	setlocale(LC_ALL, "Russian");
	printf(cstr1);
	printf(cstr2);
	cout <<'\n';
	printf("Parameter1 = %.2f, parameter2 = %d, parameter3 = %s\n\n", 1.5, 100, "\"some string\"");
	//strcat(*char, *char);



	/*char place_to_copy[255];
	char place_from_copy[] = "fewfewfergergtrklhwf";
	strcpy_s(place_to_copy, 255, place_from_copy);
	printf("Result = %s", place_to_copy);*/

	strcat_s(w,4,ws);
	//printf(cstr4);
	cout << w <<'\n';

	char str[100];
	strcpy_s(str, "1"); 
	strcat_s(str, "+");
	strcat_s(str, "2");
	strcat_s(str, "=");
	strcat_s(str, "3");
	cout << '\n' << str << '\n';

	char sraw[] = "4722";
	char answer[256] = "4722";
//	printf(strcmp(sraw, answer));
	cout << strcmp(sraw, answer)<<'\n';

	char fruit[] = "1";                        
	char answer[80]; 
	while (strcmp(fruit, answer) != 0)
	{
		cout << "Угадайте цифру от 0 до 5 >> ";
		cin >> answer;
	}           
	cout << "Правильный ответ!\n";

	char input[256];
	cout << "Введите строку: ";
	cin >> input;
	cout << "Строка " << input << " содержит " << strlen(input) << " символов\n";


	// 4
	string str1 = "";
	//str1.append() - добавить подстроку в конец
	//str.at(i) - аналог квадратных скобок str1[i]
	//str1.c_str() - преобразование строки C++ в строку С (возврат char*)
	// например, для printf("%s", str1.c_str())
	//str.clear() - сбросить строку
	//str.lenght() - длина строки
	// и много чего еще полезного

	// 5
	fstream fs;
	fs.open("example_textfile.myfile", // путь к файлу и имя
		ios::in | ios::out | ios::trunc);	// режим работы с файлом (комбинация чтения и записи)
	fs << "100500" << endl;
	fs << "some_string" << endl;
	fs << "123456.789" << endl;

	fs.seekg(0); // перейти обратно в начало
	int int1;
	fs >> int1;
	cout<<"Первая запись в файле: "<< int1<< endl;
	char buffer[255];
	fs >> buffer;
	cout << "Вторая запись в файле: " << buffer << endl;
	double dbl1;
	fs >> dbl1;
	cout << "Третья запись в файле: " << dbl1 << endl;

	fs.close();
	system("pause");
    return 0;
}

