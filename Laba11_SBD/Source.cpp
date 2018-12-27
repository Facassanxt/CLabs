// 1. ��������� ������ - ������������� ����������� ������������ ������ �������� � ���������,
// ��������� ����� ����� ������. ���������� ��������� ������ ������ � ������� �������� �� �������
// ����������� ��������� ����� ���������������� ����������� � ����������

// 2.1 �������� ����������� ��������
// �� �������� FILO (first in - last out; ������ ������ - ��������� ����).
// ���������� �����			
//					std::stack<���_������> ���_����������;
// ��������� ������ � ����
//					���_������.push(��������);
// ���������� ������ �� �����
//					���������� = ���_�����.pop();

// ������� ������������� �����: ������ ����� � ������������� ������
// ���������� ���� ���������� ��� �������� ���������� �������

// 2.2 ������� - ��� ��������� ������, ������� ��������� �� ��������
// �� �������� LILO last in - last out; ������ ������ - ��������� ����).
// �������: ������� �������������� (����������) ��������� � ������������,
// ������� ������ � ���������� ������, ������� ��������� ��������� 
// ���������� �������		
//					std::queue<���_������> ���_����������;
// ��������� ������ � �������
//					���_�������.push(��������);
// ���������� ������ �� �������
//					���������� = ���_�������.pop();

// 2.3 ������� � ����������� (priority_queue) - ��� ������� �������,
// �� � ��� ����� ������� ����������� � ����� �����,
// ����� ������� ���� ������������� �� ��������.

// 2.4 ������ ������ �������� �������-�����������
// ����������
//			std::vector<���_������> ���_�������
// ������ � �������� �������:
//			���_�������[�����] ���� ���_�������.at(�����)
// ������ �������� � ������ ����� ���� ����������� ����� IntelliSense ��� � ������������ c++


// 2.5 ����� ������� (std::array) �������� �������-����������� ��� ������� ���������� �����
// ����������
//			std::array<���_������> ���_������
// ������ � �������� �������:
//			���_�������[�����] ���� ���_�������.at(�����)
// ������ �������� � ������ ����� ���� ����������� ����� IntelliSense ��� � ������������ c++


// ��� ���������� ��������� � �������� �� ������� ������� �������� �������, ��� list,
// �� ���� ����, ��� ���������� ������ �������� � ���������� ������� ����������� ������� ���������
// ������ ������� ��� �������� �������� �� ������� �������� � ������ �������� � ��� ��� ���� �������
// ������� ������� � �������� ����������� ��������� ���, � list


// 2.6 ������ (list)
// ��� ������������ list �������� ������ ����������� � �����������, ��� � array � vector
// ������ �������� list ��-������� �������� � �� � ������� ����� �����.
// list ������� �������, ������������ �� �������.
// ������ ������� �������� � �� ��� ����������� ����������, � ������ � ��������� ������ ����������

class ListElement
{
	ListElement * next = nullptr; // ��������� �� ������� i+1, ���� ��� ������� ���������, �� next = 0
	ListElement * prev = nullptr; // ��������� �� ����� �� ������� i-1, ���� ������ ������� start,�� ���� ��������� prev = 0
	int data;
	
};

// ���������� ������ �������� ��������� 
// 1) ������ � �������� �� ������� ����������� �������� �� ������� �� 0 �������� - ��������
// ������� ����� ���������, ��� � ������ �������
// 2) ������ ������� ��� �������� ����������� ������� �������, ��� � �������/�������, �������� ��� ������ ���������


// 2.7 �������/����������� ������ (map)
// � ������, ���� ����� ������� ��������� ���������� ������, �� ������� ��� �� � �������/��������,� �
// �����-�� ���������� ���������, ������������ ��� ������ "�������" (����� ���������� "hash")
// �������: �������, �������� ������ �������� �� ������
// ���� �� ������������ ��������� ������������� � ���������� ������, � ����� ��� ��������� ��������
// ������ ������� ������������� ������� ��� ������

// 2.8 ������ (turle)
// ���� ��������� ������������� ������ ���������� ����������� ������ � ���� �������,
// ����������� ������

// 2.9 �������: �������� (pair)
// ���������� tuple, �� ������ ���� ���������


// � ����� ��� ��������, �.� ������ ��������� � ������������� ��������.
// ������ ������� ����� ��������� �� ��������� �������
// �������� ������� ��������� �� NULL
//�����������: �������� �������� � ���������� �������� �������� �� const �����





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

#include <stack>  // ���������� ���������� ��� �����
using namespace std;





int tabs = 0; //��� �������� ��������
//��������� �����
struct Branch
{
	char Data; //���� ������
	Branch *LeftBranch; //��������� �� �������� �������
	Branch *RightBranch;
};


//������� �������� ������
void Add(char aData, Branch *&aBranch)
{
	//���� ����� �� ����������
	if (!aBranch)
	{ //�������� �� � ������� � ��� ������
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}
	else //����� ������ ��������
		if (aBranch->Data > aData)//(aBranch->Data == *"[") || (aBranch->Data == *"(") || (aBranch->Data == *"{"))
		{
			//���� ��� ������ ����, ��� � ���� ����� - ������� �����
			Add(aData, aBranch->LeftBranch);
		}
		else
		{
			//����� � ����� ������
			Add(aData, aBranch->RightBranch);
		};
}

int kv, kr, xz;
bool flag = true;
void print(Branch *aBranch)
{

	if (!aBranch) return; //���� ����� �� ���������� - �������. �������� ������
	tabs++;

	for (int i = 0; i < tabs; i++) cout << "|";

	if (aBranch->Data == *"[" || aBranch->Data == *"]")
	{
		if (aBranch->Data == *"[") kv++;
		else if (kv == 0) flag = false;
		else kv--;
		cout << kv;
		cout << aBranch->Data << endl; //������ ���� �����
	}
	if (aBranch->Data == *"(" || aBranch->Data == *")")
	{
		if (aBranch->Data == *"(") kr++;
		else if (kr == 0) flag = false;
		else kr--;
		cout << kr;
		cout << aBranch->Data << endl; //������ ���� �����
	}
	if (aBranch->Data == *"{" || aBranch->Data == *"}")
	{
		if (aBranch->Data == *"{") xz++;
		else if (xz == 0) flag = false;
		else xz--;
		cout << xz;
		cout << aBranch->Data << endl; //������ ���� �����
	}

	print(aBranch->LeftBranch); //������� ����� � �� �������� �����
	print(aBranch->RightBranch);//� �����, ��� ������
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
	//6) ������
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
	// DEQUE - ��������� ������  ��� ������� ��� � �����, �������� �����  ����������� � ����������� � ���� ������ 

	/*vector < list <int>>lists;
	lists[1] = {1};
	lists[999] = {999};
	cout << get<0>(1) << endl;
	map<string, string> map1;
	map1["T-80"] = "USSR";
	map1["T-80"] = "��";
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
		vec1.clear(); //�������� ������
		vec1.insert; //
		vec1.push_back; //
		vec1[i] = 10;
		vec1.size(); // ��������� �����
		vec1.max_size();
	*/


// �������� �������, ������������� �������� ��� ������ � �������� �� ����� ���� ������ 2-�� ����� (2-� ��������)
// ��������� ������� ������ �������� (�������� ������ ������ � ������-������ ������)
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
// 2) ������ (������)
/*
	9 Ivanov
	10 Petrov
	11 Sidorov
	9 Grigoriev
	10 Sergeev
*/

	 cout << "� ����� ������ ������� 0: " << endl;
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
	 cout << "<<������������� ���������>>" << endl;
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

 //3) ������� (deque)
	 string s;
	 cout << "�������� �� �������������. ����: " << endl;
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
			 cout << "���������" << endl;
			 break;
		 }
		 else
		 {
			 cout << "�� ���������" << endl;
			 break;
		 }
	 }
	 system("pause");
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 // 4) LIST
	 /*
	front ��������� ������ � �������� �����
		-> back ��������� ����� � �������� ������
				*/

	 list<int> l1;
	 list<int> l2;
	 int n, p;
	 cout << "������� ����� list'a: ";
	 cin >> n;
	 for (int i = 0; i < n; i++)
	 {
		 cout << "����� [" << i + 1 << "]: ";
		 cin >> p;
		 l1.push_back(p);
		 l2.push_back(p);
	 }

	 l1.sort();

	 cout << "����� ����������: ";
	 for (int i = 0; i < n; i++)
	 {
		 cout << l1.front() << " ";
		 l1.pop_front();
	 }

	 l2.sort(greater<int>());

	 cout << '\n' << "����� ����������: ";
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
	 //1) ����� ������
	stack <char> stack;
	string mes;
	int i, kv = 0,kz = 0; 
	while (kv < 1)
	{
		cout << "������� ���������: ";
		getline(cin, mes);
		if (mes == "stop")
		{
			cout << "����� �������� ������� =) \n";
			system("pause");
			return 0;
		}
		for (i = 0; i < mes.length(); i++) // ���� �� �� ����� ���������
		{
			if ((mes[i] == *"(") || (mes[i] == *"[") || (mes[i] == *"{")) stack.push(mes[i]); // ���� ������ ��������, �� �� �����

			// ���� ������ ������� ������ � ����� ��� ���� �� ����, �� �������� � ������ ����� �� ����� 0 (���� �� ��������� ��� ��������� � �����), �� �� ������� ��������������� ������ � �����
			if (stack.size() != 0 && (((mes[i] == *")") && (stack.top() == *"(")) || ((mes[i] == *"]") && (stack.top() == *"[")) || ((mes[i] == *"}") && (stack.top() == *"{")))) stack.pop();

			// ���� �� �� ������� ��������������� ������, �� ��������� ���������, ��� ���� ����� ��������� ������� ��� ������� ������� ����������� ������ ��� �������� ������ 
			else if ((mes[i] == *")") || (mes[i] == *"]") || (mes[i] == *"}"))
			{
				kz = 1;
				cout << "False" << endl;
				break;
				//return 0;
			}//stack.push(mes[i]);
			/*if (mes[i] == *"(") // ���� ����� " ( " , ����� � ����
			{
				kv++;
				stack.push(mes[i]);
				cout << "����� �����: " << kv << stack.top() << endl;
			}
			if (mes[i] == *")" && stack.size() > 0 && stack.top() == *"(") // ���� ����� " ) " � ����� ��� ���� " ( ", ������
			{
				kv--;
				cout << "����� �����: " << kv << endl;
				stack.pop();
			}
			else if (mes[i] == *")") // ���� �� � ��� ��� ����� ��� ��� " ( " , �� ����� ��� ���� ����� ������ False �.� ��� ������
			{
				stack.push(mes[i]);
				cout << "����� �����: " << stack.top() << endl;
			}

			if (mes[i] == *"[")
			{
				kz++;
				stack.push(mes[i]);
				cout << "����� �����: " << kz << stack.top() << endl;
			}
			if (mes[i] == *"]" && stack.size() > 0 && stack.top() == *"[")
			{
				kz--;
				cout << "����� �����: " << kz << endl;
				stack.pop();
			}
			else if (mes[i] == *"]")
			{
				stack.push(mes[i]);
				cout << "����� �����: " << stack.top() << endl;
			}

			if (mes[i] == *"{")
			{
				kr++;
				stack.push(mes[i]);
				cout << "����� �����: " << kr << stack.top() << endl;
			}
			if (mes[i] == *"}" && stack.size() > 0 && stack.top() == *"{")
			{
				kr--;
				cout << "����� �����: " << kr << endl;
				stack.pop();
			}
			else if (mes[i] == *"}")
			{
				stack.push(mes[i]);
				cout << "����� �����: " << stack.top() << endl;
			}*/
		}
		// �������� ����� �� �������
		if (stack.empty() && kz != 1) cout << "���� ���� \n" << "True " << endl;
		else if (stack.size() > 0)
		{
			if (kz == 1);
			else cout << "���� �� ���� \n" << "False " << endl;
		}
		kz = 0;
		while (stack.size() > 0) stack.pop();
	}
	system("pause");
	return 0;
}