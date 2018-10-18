// Laba6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#include <Bitset>
using namespace std;
// Наследование - объявление производных классов от родительских при
// котором в производном классе включаются выбранные свойства и методы
// родительских без их повторного объявления

// 1. ОПРЕДЕЛЕНИЕ И СИНТАКСИС
// Синтаксис:
// class имя_нового класса: [тип_наследования] имя_родительского_класса1,
//							[тип_наследования] имя_родительского_класса2
// {
// //...
// }


// где "тип_наследования" - тоже public, protected и private
// Указывать не обязательно


// 2.ЗАДАНИЕ
//Создать класс weapon с самыми общими для любого оружия свойствами и методами
// создать производный класс launcher и rifle

class Weapon
{

public:
	int DMG = 1;
	double fire_rate;
	bool splash;
	double gun_weight;
	double rage;
	double reload_time;
	virtual void bullet() { ; };
};
class launcher : public Weapon
{
public:
	int DMG = 100/2;
	void bullet() { std::cout << "Fire!" << std::endl; }
	
};
class rifle: public Weapon
{
public:

};

int main()
{
	launcher *laun = new launcher;
	cout << (*laun).DMG <<'\n';
	(*laun).bullet();
	Weapon *weap = new Weapon;
	cout << (*weap).DMG << '\n';

	getchar();
	return 0;
}