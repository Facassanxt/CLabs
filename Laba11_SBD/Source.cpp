// 1. Структура данных - архитектурная конструкция определяющая методы хранения и обработки,
// связанных между собой данных. Простейшая структура данных массим с доступу элемента по индексу
// реализуется механикой языка программирования компилятора и процессора

// 2.1 ПЕРЕЧЕНЬ СТАНДАРТНЫХ СТРУКТУР
// по принципу FILO (first in - last out; первый пришел - последний ушел).
// Объявление стека			
//					std::stack<тип_данных> имя_переменной;
// Помещение данных в стек
//					имя_стекаю.push(значение);
// Извлечение данных из стека
//					переменная = имя_стека.pop();

// Примеры использования стека: анализ числа и закрывающихся скобок
// Аппаратный стек процессора для передачи параметров функций

// 2.2 Очередь - это структура данных, которая построена по принципу
// по принципу LILO last in - last out; первый пришел - последний ушел).
// Примеры: Очередь депонированных (отложенных) сообщений в мессенджерах,
// очередь команд в скриптовых языках, очередь системных сообщений 
// Объявление очереди		
//					std::queue<тип_данных> имя_переменной;
// Помещение данных в очередь
//					имя_очереди.push(значение);
// Извлечение данных из очереди
//					переменная = имя_очереди.pop();

// 2.3 Очередь с приоритетом (priority_queue) - это обычная очередь,
// но в ней новый элемент добавляется в такое место,
// чтобы очередь была отсортирована по убыванию.

// 2.4 Вектор Вектор является классом-контейнером
// Объявление
//			std::vector<тип_данных> имя_вектора
// Доступ к элементу вектора:
//			имя_вектора[номер] либо имя_вектора.at(номер)
// прочие свойства и мотоды могут быть просмотрены через IntelliSense или в документации c++


// 2.5 Класс массива (std::array) является классом-контейнером для массива постоянной длины
// Объявление
//			std::array<тип_данных> имя_класса
// Доступ к элементу вектора:
//			имя_массива[номер] либо имя_массива.at(номер)
// прочие свойства и мотоды могут быть просмотрены через IntelliSense или в документации c++


// При выполнении обращения к элементу по индекчу массивы работают быстрее, чем list,
// за счет того, что вычисление адреса элемента в квадратных скобках выполняется простым сложением
// однако вставка или удаление элемента из массива приводит к сдвигу соседних с той или иной стороны
// поэтому вставка и удаление выполняются медленнее чем, в list


// 2.6 Список (list)
// Для программиста list обладает схожим интерфейсом и назначением, что и array и vector
// однако элементы list по-другому хранятся в ОП и связаны между собой.
// list подобен цепочке, составленной из звеньев.
// Каждый элемент хранится в ОП как независимая переменная, и связан с соседними парами указателей

class ListElement
{
	ListElement * next = nullptr; // указатель на элемент i+1, если это элемент последний, то next = 0
	ListElement * prev = nullptr; // указатель на такой же элемент i-1, если данный элемент start,то надо присвоить prev = 0
	int data;
	
};

// Вследствие такого хранения элементов 
// 1) доступ к элементу по индексу выполняется проходом по цепочке от 0 элемента - операция
// намного более затратная, чем в случае массива
// 2) Однако вставка или удаление выполняется намного быстрее, чем в массиве/векторе, особенно чем больше элементов


// 2.7 Словарь/именованный список (map)
// в случае, если нужно хранить множество однотипных данных, но связаны они не с номером/индексом,а с
// каким-то нечисловым значением, используется тип данных "словарь" (иначе называется "hash")
// Примеры: словарь, хранение набора настроек по именам
// ключ по специальному алгоритму преобразуется в порядковый индекс, и далее вся остальная механика
// класса словаря соответствует вектору или списку

// 2.8 Кортеж (turle)
// Если возникает необходимость увязки совершенно разнородных данных в один элемент,
// приминяется картеж

// 2.9 Деревья: бинарные (pair)
// аналогично tuple, но хранит пару элементов


// В стеке нет индексов, т.е нельзя обратится к определенному элементу.
// Каждый элемент имеет указатель на следующий элемент
// Головной элемент указывает на NULL
//Достоинства: операция удаления и добавление элемента делаются за const время





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
#include <queue> 

#include <stack>  // подключаем библиотеку для стека
using namespace std;





int tabs = 0; //Для создания отступов
//Структура ветки
struct Branch
{
	char Data; //Поле данных
	Branch *LeftBranch; //УКАЗАТЕЛИ на соседние веточки
	Branch *RightBranch;
};


//Функция внесения данных
void Add(char aData, Branch *&aBranch)
{
	//Если ветки не существует
	if (!aBranch)
	{ //создадим ее и зададим в нее данные
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}
	else //Иначе сверим вносимое
		if (aBranch->Data > aData)//(aBranch->Data == *"[") || (aBranch->Data == *"(") || (aBranch->Data == *"{"))
		{
			//Если оно меньше того, что в этой ветке - добавим влево
			Add(aData, aBranch->LeftBranch);
		}
		else
		{
			//Иначе в ветку справа
			Add(aData, aBranch->RightBranch);
		};
}

int kv, kr, xz;
bool flag = true;
void print(Branch *aBranch)
{

	if (!aBranch) return; //Если ветки не существует - выходим. Выводить нечего
	tabs++;

	for (int i = 0; i < tabs; i++) cout << "|";

	if (aBranch->Data == *"[" || aBranch->Data == *"]")
	{
		if (aBranch->Data == *"[") kv++;
		else if (kv == 0) flag = false;
		else kv--;
		cout << kv;
		cout << aBranch->Data << endl; //Данные этой ветки
	}
	if (aBranch->Data == *"(" || aBranch->Data == *")")
	{
		if (aBranch->Data == *"(") kr++;
		else if (kr == 0) flag = false;
		else kr--;
		cout << kr;
		cout << aBranch->Data << endl; //Данные этой ветки
	}
	if (aBranch->Data == *"{" || aBranch->Data == *"}")
	{
		if (aBranch->Data == *"{") xz++;
		else if (xz == 0) flag = false;
		else xz--;
		cout << xz;
		cout << aBranch->Data << endl; //Данные этой ветки
	}

	print(aBranch->LeftBranch); //Выведем ветку и ее подветки слева
	print(aBranch->RightBranch);//И ветки, что справа
	tabs--;
	return;
}

void FreeTree(Branch *aBranch)
{
	if (!aBranch) return;
	FreeTree(aBranch->LeftBranch);
	FreeTree(aBranch->RightBranch);
	delete aBranch;
	return;
}








int main()
{
	setlocale(LC_ALL, "rus");
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//6) ДЕРЕВО
	Branch *Root = 0;
	char so[] = ")([{}])(";

	for (int i = 0; so[i]; i++)
	{
		Add(so[i], Root);
	}

	print(Root);
	FreeTree(Root);
	if ((kv || kr || xz != 0) || (flag == false))
	{
		cout << "\tBAD =(";
	}
	else
	{
		cout << "\tGOOD =)";
	}
	cin.get();
	// DEQUE - структура данных  как очереди так и стека, элементы могут  добавляться и извлекаться с двух сторон 

	/*vector < list <int>>lists;
	lists[1] = {1};
	lists[999] = {999};
	cout << get<0>(1) << endl;
	map<string, string> map1;
	map1["T-80"] = "USSR";
	map1["T-80"] = "РФ";
	map1["Merkava"]  = "Israel";
	map1["M1 Abrams"] = "USA";
	map1["Leclerc"] = "France";

	cout << map1["T-80"] << endl;
	cout << map1["Leclerc"] << endl;

	tuple <string, string, double, int> tank1 = {"T-80","RF",80.5,65};
	tuple <string, string, double, int> tank2;
	tank2 = { "Leclerk","France",65.0,55 };
	
	cout << "Name: " << get<0>(tank1) << endl;
	cout << "State: " << get<1>(tank1) << endl;
	cout << "Speed: " << get<2>(tank1) << endl;
	cout << "NOR: " << get<3>(tank1) << endl;
	cout << "Name: " << get<0>(tank2) << endl;
	cout << "State: " << get<1>(tank2) << endl;
	cout << "Speed: " << get<2>(tank2) << endl;
	cout << "NOR: " << get<3>(tank2) << endl;
	setlocale(LC_ALL, "rus");
	*/

	/*	vector<int> vec1;
		int i;
		vec1.clear(); //очистить массив
		vec1.insert; //
		vec1.push_back; //
		vec1[i] = 10;
		vec1.size(); // выявление длины
		vec1.max_size();
	*/


// Бинарные деревья, разновидность структур баз дерево у которого не может быть больше 2-ух узлов (2-а дочерних)
// ИЗвестные частные случае деревьев (Двоичное дерево поиска и Красно-черное дерево)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*	list <double> l1;
	class list_element   
	{
		double data;
		list_element * pnext = *new list_element*[2];
		list_element * ppnev;
	};
*/
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//0) Vector + tuple
typedef vector< tuple<string, string, double, int> > my_tuple; 
 my_tuple t, t2; 
 t.push_back(tuple <string, string, double, int>("T-80", "RF", 80.5, 65)); 
 t2.push_back(tuple <string, string, double, int>("Leclerc", "France", 65.0, 55)); 
 for (my_tuple::const_iterator Tank = t.begin(); Tank != t.end(); ++Tank)
 {
	 for (my_tuple::const_iterator Tank2 = t2.begin(); Tank2 != t2.end(); ++Tank2)
	 {
		 cout << "Characteristic <<T-80>>: " << endl;
		 cout << "Name: " << get<0>(*Tank) << endl;
		 cout << "State: " << get<1>(*Tank) << endl;
		 cout << "Speed: " << get<2>(*Tank) << endl;
		 cout << "N of round: " << get<3>(*Tank) << endl << endl;

		 cout << "Characteristic <<Leclerc>>: " << endl;
		 cout << "Name: " << get<0>(*Tank2) << endl;
		 cout << "State: " << get<1>(*Tank2) << endl;
		 cout << "Speed: " << get<2>(*Tank2) << endl;
		 cout << "N of round: " << get<3>(*Tank2) << endl;
	 }
 }
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2) ЗААНИЕ (Классы)
/*
	9 Ivanov
	10 Petrov
	11 Sidorov
	9 Grigoriev
	10 Sergeev
*/

	 cout << "В конце списка введите 0: " << endl;
	 queue <string> cl_9, cl_10, cl_11;
	 string Fam;
	 int cl;
	 cin >> cl;
	 for (;;)
	 {
		 getline(cin, Fam);
		 if (cl == 0)
		 {
			 break;
		 }
		 else if (cl == 9)
		 {
			 cl_9.push(Fam);
		 }
		 else if (cl == 10)
		 {
			 cl_10.push(Fam);
		 }
		 else if (cl == 11)
		 {
			 cl_11.push(Fam);
		 }


		 cin >> cl;
	 }
	 cout << "<<Распределение выполнено>>" << endl;
	 cout << "Class 9:" << endl;
	 while (!cl_9.empty())
	 {
		 cout << cl_9.front() << endl;
		 cl_9.pop();
	 }
	 cout << endl << "Class 10:" << endl;
	 while (!cl_10.empty())
	 {
		 cout << cl_10.front() << endl;
		 cl_10.pop();
	 }
	 cout << endl << "Class 11:" << endl;
	 while (!cl_11.empty())
	 {
		 cout << cl_11.front() << endl;
		 cl_11.pop();
	 }
	 cout << "-----------" << endl;
	 cout << "End of list" << endl;


 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 //3) Задание (deque)
	 string s;
	 cout << "Проверка на палидромность. Ввод: " << endl;
	 getline(cin, s);
	 deque<int> deq;
	 for (int i = 0; i < s.length(); i++) 
	 {
		 deq.push_front (s[i]);
	 }
	 for (int i = 0; i < s.length(); i++)
	 {
		 if ((deq.size() > 1) && deq.front() == deq.back())
		 {
			 deq.pop_front();
			 deq.pop_back();
		 }
		 else if (deq.size() == 1 || deq.empty())
		 {
			 cout << "Палиндром" << endl;
			 break;
		 }
		 else
		 {
			 cout << "Не палиндром" << endl;
			 break;
		 }
	 }
	 system("pause");
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 // 4) LIST
	 /*
	front добавляет вправо и сдвигает влево
		-> back добавляет влево и сдвигает вправо
				*/

	 list<int> l1;
	 list<int> l2;
	 int n, p;
	 cout << "Введите длину list'a: ";
	 cin >> n;
	 for (int i = 0; i < n; i++)
	 {
		 cout << "Вввод [" << i + 1 << "]: ";
		 cin >> p;
		 l1.push_back(p);
		 l2.push_back(p);
	 }

	 l1.sort();

	 cout << "Вывод сортировки: ";
	 for (int i = 0; i < n; i++)
	 {
		 cout << l1.front() << " ";
		 l1.pop_front();
	 }

	 l2.sort(greater<int>());

	 cout << '\n' << "Вывод сортировки: ";
	 for (int i = 0; i < n; i++)
	 {
		 cout << l2.front() << " ";
		 l2.pop_front();
	 }
	 cout << endl;
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 // 5) Map

	 map<string, string> map1;
	 map1["T-80"] = "USSR";
	 map1["Merkava"] = "Israel";
	 map1["M1 Abrams"] = "USA";
	 map1["Leclerc"] = "France";
	 string z;
	 printf("Tank name: ");
	 cin >> z;
	 cout << "Country: " << map1[z] << endl;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 //1) Поиск скобок
	stack <char> stack;
	string mes;
	int i, kv = 0,kz = 0; 
	while (kv < 1)
	{
		cout << "Введите сообщение: ";
		getline(cin, mes);
		if (mes == "stop")
		{
			cout << "Выход выполнен успешно =) \n";
			system("pause");
			return 0;
		}
		for (i = 0; i < mes.length(); i++) // идем от по всему сообщению
		{
			if ((mes[i] == *"(") || (mes[i] == *"[") || (mes[i] == *"{")) stack.push(mes[i]); // Если скобка открытая, мы ее пушим

			// Если нахоим закртыю скобку и перед ней того же типа, но открытая и размер стака не равен 0 (чтоб не крашилось при сравнении с топом), то мы удаляем противоположную скобку в стаке
			if (stack.size() != 0 && (((mes[i] == *")") && (stack.top() == *"(")) || ((mes[i] == *"]") && (stack.top() == *"[")) || ((mes[i] == *"}") && (stack.top() == *"{")))) stack.pop();

			// Если мы не находим противоположную скобку, мы завершаем программу, для того чтобы исключить вариант при которой сначало открывается скобка или остаются лишнии 
			else if ((mes[i] == *")") || (mes[i] == *"]") || (mes[i] == *"}"))
			{
				kz = 1;
				cout << "False" << endl;
				break;
				//return 0;
			}//stack.push(mes[i]);
			/*if (mes[i] == *"(") // Если нашли " ( " , пушим в стак
			{
				kv++;
				stack.push(mes[i]);
				cout << "Вывод стака: " << kv << stack.top() << endl;
			}
			if (mes[i] == *")" && stack.size() > 0 && stack.top() == *"(") // Если нашли " ) " и перед ней есть " ( ", попаем
			{
				kv--;
				cout << "Вывод стака: " << kv << endl;
				stack.pop();
			}
			else if (mes[i] == *")") // Если же у нас нет перед ней нет " ( " , то пушим для того чтобы выдать False т.к она лишняя
			{
				stack.push(mes[i]);
				cout << "Вывод стака: " << stack.top() << endl;
			}

			if (mes[i] == *"[")
			{
				kz++;
				stack.push(mes[i]);
				cout << "Вывод стака: " << kz << stack.top() << endl;
			}
			if (mes[i] == *"]" && stack.size() > 0 && stack.top() == *"[")
			{
				kz--;
				cout << "Вывод стака: " << kz << endl;
				stack.pop();
			}
			else if (mes[i] == *"]")
			{
				stack.push(mes[i]);
				cout << "Вывод стака: " << stack.top() << endl;
			}

			if (mes[i] == *"{")
			{
				kr++;
				stack.push(mes[i]);
				cout << "Вывод стака: " << kr << stack.top() << endl;
			}
			if (mes[i] == *"}" && stack.size() > 0 && stack.top() == *"{")
			{
				kr--;
				cout << "Вывод стака: " << kr << endl;
				stack.pop();
			}
			else if (mes[i] == *"}")
			{
				stack.push(mes[i]);
				cout << "Вывод стака: " << stack.top() << endl;
			}*/
		}
		// Проверка стака на пустоту
		if (stack.empty() && kz != 1) cout << "Стак пуст \n" << "True " << endl;
		else if (stack.size() > 0)
		{
			if (kz == 1);
			else cout << "Стак не пуст \n" << "False " << endl;
		}
		kz = 0;
		while (stack.size() > 0) stack.pop();
	}
	system("pause");
	return 0;
}