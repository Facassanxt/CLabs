
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#include <Bitset>
using namespace std;

class vehicle // игровое транспортное средство
{
public:
	vehicle() /*Могут быть входные параметры!*/ // конструктор
	{
		std::cout << "constructor (vehicle)" << std::endl;
		return;
	}

	~vehicle() /*Не могут быть входные параметры!*/ // деструктор
	{
		std::cout << "~constructor of vehicle" << std::endl;
		return;
	}
};

void func()
{

	vehicle vehicle_object;

};

int main()
{
	func();
	getchar();
	return 0;
}