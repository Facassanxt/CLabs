


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
	int * ptr_int;
	double * ptr_dbl;
	cout << "Вывод: тип данных - размер указателя \n"
		<< "int pointer size = " << sizeof(ptr_int) << "\n"
		<< "double pointer size = " << sizeof(ptr_dbl) << "\n"
		<< "char pointer size = " << sizeof(char *) << "\n"
		<< "long long pointer size = " << sizeof(long long *) << "\n"
		<< "bool pointer size = " << sizeof(bool *) << "\n"
		<< endl;


	cout << "Шифр Цезаря\n";
	char mes[999], ch; //сообщение
	int i, key;

	cout << "Введите сообщение: ";
	cin.getline(mes,999);
	cout << "Введите ключ: ";
	cin >> key;
	for (i = 0; mes[i] != '\0'; i++) // '\0' - это конец строки mes
	{
		ch = mes[i];

		if (ch >= 'a' && ch <= 'z') //Строчный регистр
		{
			ch = ch + key;

			if (ch > 'z') 
			{
				ch = ch - 'z' + 'a' - 1;
			}


			mes[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') // Заглавный регистр
		{
			ch = ch + key;

			if (ch > 'Z') 
			{
				ch = ch - 'Z' + 'A' - 1;
			}

			mes[i] = ch;
		}
	}

	cout << "Зашифрованное сообщение: " << mes;


		cout << "\n\nСортировка пузырьком\n";
	int *arr; // указатель для выделения памяти под массив
	int size; // размер массива
	int temp; // временная переменная для обмена элементов местами
	
			  // Ввод количества элементов массива
	cout << "Введите кол-во чисел \n";
	cin >> size;
	if (size > 0)
	{

		arr = new int[size]; // выделение памяти под массив

							 // заполнение массива
		for (int i = 0; i < size; i++)
		{
			cout << "[" << i + 1 << "] = ";
			cin >> arr[i];
		}
		cin.ignore();

		// Сортировка массива пузырьком
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					// меняем элементы местами
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}

		// Вывод отсортированного массива на экран
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
			arr[i] = 0;
		}

	}
	else
	{
		cout << "Ошибка\n";
	}
	cin.ignore();
	

	cout << "\nШейкерная cортировка\n";
	cout << "Введите кол-во чисел \n";
	cin >> size;
	if (size > 0)
	{

		arr = new int[size]; // выделение памяти под массив

							 // заполнение массива
		for (int i = 0; i < size; i++)
		{
			cout << "[" << i + 1 << "] = ";
			cin >> arr[i];
		}
		cin.ignore();

		// Сортировка массива
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					// меняем элементы местами
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
				if (arr[size - 1 - j] < arr[size - 2 - j])
				{
					temp = arr[size - 1 -j];
					arr[size - 1 - j] = arr[size - 2 - j];
					arr[size - 2 - j] = temp;
				}
			}
		}

		// Вывод отсортированного массива на экран
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
			arr[i] = 0;
		}

	}
	else
	{
		cout << "Ошибка";
	}
	cin.ignore();


	getchar();
	return 0;
}
