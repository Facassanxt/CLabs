

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
	string stroka = "Языки";

	cout << stroka + 2 << "  ";

	getchar();
	return 0;
}


/*var s, v:string;
i, kol, max:integer;
begin
writeln('Заклинание');
readln(s);
kol: = 0;
for i: = 1 to length(s) do
if (s[i] in['A'..'Z']) or (s[i] in['a'..'z']) then kol : = kol + 1
else begin
if kol>max then max : = kol;
kol: = 0;
end;
If max>kol then writeln(max)
else begin max : = kol; writeln(max) end;
for i: = 1 to length(s) do
if (s[i] in['A'..'Z']) or (s[i] in['a'..'z']) then begin
if ((word(s[i]) - word(max)) < word('A')) then begin
max : = max - 1;
v: = char(word('Z') - (word(max) - (word(s[i]) - word('A'))));
write(v);
max: = max + 1;
end
else if ((word(s[i]) - word(max)) < word('a')) and ((word(s[i]) - word(max)) > word('Z')) then begin
max : = max - 1;
v: = char(word('z') - (word(max) - (word(s[i]) - word('a'))));
write(v);
max: = max + 1;
end
else if ((word(s[i]) - word(max)) <= (word('Z'))) and (word(s[i])>word('a'))  then begin
max : = max - 1;
v: = char(word('z') - (word(max) - (word(s[i]) - word('a'))));
write(v);
max: = max + 1;
end
else
Write(char(word(s[i]) - word(max)));
end
else write(' ');
end.*/