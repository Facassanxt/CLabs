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

/* создать класс матриц matrix размера m*n, 1<=m<=10, 1<=n<=10, c операциями 
1) сложение bool summMatrix(matrix matr2); 
a b + 
k l = 
a+k b+l 
c d 
m n 
c+m d+n 
верно, размеры матриц совпадают 
2) умножение bool multMatrix(matrix matr2); 
a11 a12 a13 
b11 b12 
c11 c12 
a21 a22 a23 * b21 b22 = c21 c22 b31 b32 c21 = a21*b11+a22*b21+a23*b31 cij = ai1*b1j+ai2*b2j+...+ain*bnj 
верно, если columns(a)=rows(b) 
3) транспонирование bool transp(); 
| a11 a12 a13|* a11 a21 | a21 a22 a23| = a12 a22 a13 a23 
4) печать bool print(); 
5) ввод с клавиатуры bool input(); 
создать класс-наследник вектор vector, длиной n, 1<=n<=10, c дополнительными операциями 
1) скалярное произведение double scalMultVector(vector vec2); 
(a1 a2 a3)*(b1 b2 b3) = a1*b1+a2*b2+a3*b3 верно, если размеры соврадают 
2) умножение вектора на число 
(a1 a2 a3)*k = (a1*k a2*k a3*k) 


#include "pch.h" 
#include <iostream> 
class matrix

{
private:

	double matr[10][10];
	int rows;
	int columns;
public:
	matrix();
	~matrix();
	//void 
	matrix(int p_rows, int p_colums, int p_matr[10][10]);
	bool input();
	bool print();
	bool
		summMatrix(matrix matr2);
	bool
		multMatrix(matrix matr2);
	bool transp();

	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return columns;
	}
	double getElem(int row, int col)
	{
		if (row<rows && col<columns && row>-1 && col>-1)
		{
			return matr[row][col];
		}
		std::cout « "Connot get elenent. Index Error!\n";
		return -1;
	}
};

int main()
{
	matrix matrA, matrB;
	matrA.input();
	matrB.input();
	matrA.transp();
	matrA.print();
	matrA.summMatrix(matrB);
	matrA.print();
	matrA.multMatrix(matrB);
	matrA.print();
	return 0;
}
matrix::matrix()
{
}
matrix::~matrix()
{
}
bool matrix::input()
{
	//считать количество строк 
	//проверить, что введенно число в пределах [1,10] 
	//иначе вернуть ошибку 
	//считать количество столбцов 
	//проверить, что введенно число в пределах [1,10] 
	//иначе вернуть ошибку 
	//считать элементы матрицы 
	return true;
}
*/