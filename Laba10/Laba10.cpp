// Laba10.cpp: определяет точку входа для консольного приложения.
/*
int main()
{
LibClass ojb1;
cout <<"Hello World!\n";
}
*/
// 1.1"СТАТИЧЕСКИЕ БИБЛИОТЕКИ" 
// 1.Библиотеки подключаемые в виде исходных кодов 
// как правило файл с расширением *.h или *.hpp, либо пара файлов 
// *.h и *.hpp и содинаковым названием. Содержит объявление и определение 
// переменных, констант, функций и классов. Подключаются в приложение 
// через #include заголовочного файла 
// В h как правило приводится объявление сущьностей, а в *.cpp раскрывается 
// определение (реализация). Такой подход повышает читаемость структурированность 
// когда 

// Преемущества: 
// 1)Исходный код открыт 
// 2)Его всегда можно модифицировать и исправить 
// 3)Простота подключения 
// Недостаток: 
// 1)При малейшем изменении в приложении, перекомпилируется и перестраевается весь проект, 
// включая и библиотеку, даже если она сама не менялась. 
// Недостаток прошлого подхода компенсируется, если библиотечный код предварительно 
// подключать в приложении 

// Преемущество: 
// 1)Более быстрая пересборка проекта 
// 2) Так как код из библиоеки встраивается в *.ехе, он не потеряется 
// Недостатки: 
// 1)бинарники *.lib надо сначала найти или построить самим из исходников 
// 2)бинарная не совместимость: *.lib должны подходить под 
// - платформу (OC и окружение) 
// - аппаратура, тип процессора и разрядность. 
// - компилятор и т.д. 
// 3) Затруднительность аудита безопасности бинарных файлов 
// по данной причине библиотеки связанные с информационной безопасностью, шифрованием, защитой 
// распространяются только в виде исходников, из которых разработчик 
// на месте должен сначала построить *.lib 
// в *.nix системах аналог *.lib файлы 
// 4) Размер ЕХЕ файл увиличивается, так как код функции из *.lib 

// 1.2 ПОДКЛЮЧЕНИЕ СТАТИЧЕСКОЙ БИБЛИОТЕКИ 
// 1. При отсутствии бинарников исходники библиотеки собирать в 
// *.lib(настройки -> "Тип конфигурации") 
// 2. В настройках проекта VS "Компоновщик" -> "Ввод" 
// добавить название файла библиотеки *.lib 
// 3. В "Каталоги VC++" добавить путь к библиотеке 
// 4. В исходниках вашего проекта объявить функцию со спецификатором extern 
// или добавить *.h файл библиотеки 

// Сведения преложения и подключённой сатитич еской библиотеки 
// производит уже после компеляции, на следуйщем этапесборки 
// Линкер ищет функциюпо имени *.lib-file. Если находит - берёт машинный код 
// функции и дописывает к *.exe. Если нет - возникает ошибка LNK2019 или 
// схожие 

// 3. ДИНАМИЕСКИЕ БИБЛИОТЕКИ 
// *.dll (Dynamic Link Librari)

#include <iostream> 
#include "stdafx.h"
#include "Mat_lib.h"
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#include <Bitset>

using namespace std;


int main()
{
	matrix a(2, 2);
	matrix b(2, 2);
	matrix t(2, 2);
	matrix c;
	matrix z;
	a.set();
	b.set();
	t.set();
	c = a + b;
	a += b;
	z = a * b;
	t *= b;


	c.print();
	a.print();
	z.print();
	t.print();

	system("Pause");
	return 0;
}