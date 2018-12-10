//#include "stdafx.h" 
#include <iostream> 
#include <conf.h> // функции, структуры и константы настройки OpenSSL 
#include <conf.h> 
#include <evp.h> // сами криптогрфические функции https://wiki.openssl.org/index.php/EVP 
#include <err.h> // коды внутренних ошибок OpenSSL и их расшифровка 
#include <aes.h> 
#include <fstream> 
#include <locale.h>

#pragma comment (lib, "ws2_32.LIB") 
#pragma comment (lib, "gdi32.LIB") 
#pragma comment (lib, "advapi32.LIB") 
#pragma comment (lib, "crypt32") 
#pragma comment (lib, "user32") 
#pragma comment (lib, "wldap32") 

// библиотеки OpenSSL (openssl.org) подключаются неявно динамически (см. конспект лаб. по библиотекам) 

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	fstream first("plaintext.txt", ios::binary | ios::in);
	fstream second("cryptedtext.txt", ios::binary | ios::out | ios::in);
	fstream third("decrypted.txt", ios::binary | ios::out);

	// работа с криптофункциями OpenSSL: 
	// 1) создание объекта с настройками 
	// 2) собственно, шифрование 
	// 3) финализация 
	// 4) и вывод зашифрованных данных 

	// как правило, в литературе, структуры используются для хранения только данных 
	// ни слова о методах и конструкторах/деструкторах 
	struct name_of_my_struct // сродни классу 
	{
		name_of_my_struct()
		{

		}

		int a;
		double b;
		int fnc1()
		{
			return a;
		}
	};
	
//	unsigned char *plaintext =
//		(unsigned char *)"EVP_EncryptUpdate() encrypts inl bytes from the buffer in and writes the encrypted version to out";// исходный текст 
//	int plaintext_len = strlen((char *)plaintext); // длина текста 

	unsigned char plaintext[256 * 100] = {};
	unsigned char cryptedtext[256 * 100] = {}; // зашифрованный результат 
	unsigned char decryptedtext[256 * 100] = {}; // расшифрованный результат 

	unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ) 
	unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер 


	// 1. Создаётся указатель на несуществующую структуру 
	// структура - тип данных в C++, близка к КЛАССУ, различия минимальны 
	EVP_CIPHER_CTX *ctx; // structure 

	// 2. Для указателя создаётся пустая структура настроек (метод, ключ, вектор инициализации и т.д.) 
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода 

	// 3. Структура EVP_CIPHER_CTX заполняется настройками 
	EVP_EncryptInit_ex(ctx, // ссылка на объект/структуру, куда заносятся параметры 
		EVP_aes_256_cbc(), // ссылка на шифрующее ядро AES 256 (функцию с алгоритмом) 
		NULL,
		key, // ключ/пароль/секрет 
		iv); // рандомайзер (случайный начальный вектор) 

	//ОТКРТЫТИЕ ФАЙЛОВ (2 ШТ) в бинарном режиме

	first.read((char*)plaintext, sizeof(plaintext));
	int plaintext_len = strlen((char *)plaintext);

	int razmer;
	if (plaintext_len % 256 == 0)
	{
		razmer = plaintext_len / 256;
	}

	else
	{
		razmer = (plaintext_len / 256) + 1;
	}

	//Зациклить{
		//В 1-ый файл
		// 4. САМ ПРОЦЕСС ШИФРОВАНИЯ - ФУКНЦИЯ EVP_EncryptUpdate 
		int len;
		int cryptedtext_len = 0;
		for (int i = 0; i < razmer; i++)
		{
			EVP_EncryptUpdate(ctx, // объект с настройками 
				cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные 
				&len, // выходной параметр: длина полученного шифра 
				plaintext, // входной параметр: что шифровать 
				plaintext_len); // входной параметр : длина входных данных 
			cryptedtext_len = len;
			//Запист во 2-ой файл
		//Конец цикла }	
		}


		// 5. Финализация процесса шифрования 
		// необходима, если последний блок заполнен данными не полностью 
		EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	// Записать в файл финальную порцию и закрыть 
		cryptedtext_len += len;
		cout << "Длина полученного шифра" << cryptedtext_len << endl;
		cout << "Длина исходника" << plaintext<< endl;
		cout << "Длина полученного шифра" << cryptedtext_len << endl;


		second.write((char*)&cryptedtext, sizeof(cryptedtext));
		cout << "Зашифрованный текст"<< endl;
		// 6. Удаление структуры 
		EVP_CIPHER_CTX_free(ctx);

		// вывод зашифрованных данных 
		for (int i = 0; i < cryptedtext_len; i++)
		{
			cout << hex << cryptedtext[i];
			if ((i + 1) % 32 == 0) cout << endl;
		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	// РАСШИФРОВКА 

	// 1. 
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода 

	// 2. 
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // инициализация методом AES, ключом и вектором 

	// 3. 
	EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len); // СОБСТВЕННО, ШИФРОВАНИЕ 

	// 4. 
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

	// 5. 
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	cout << decryptedtext << endl;

	// —- шифрование файла 
	// производится точно так же, но порциями, в цикле 
	// в цикле 
	/*
	1) открытие файлов и настройка параметров OpenSSL
	2) считывание первого блока
	3) while(считанный_фрагмент > 0)
	{
	4) шифрование считанного
	5) запись зашифрованного массива в файл
	6) считывание следующего фрагмента
	}
	7)

	применение финализирующей фукнции
	8) запись финализирующего блока в файл
	9) закрытие файлов
	*/
	getchar();
	return 0;
}