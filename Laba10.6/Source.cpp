#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
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

//#define BUFLEN 256
// библиотеки OpenSSL (openssl.org) подключаются неявно динамически (см. конспект лаб. по библиотекам)

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	unsigned char *plaintext = (unsigned char *)"";// исходный текст
	int plaintext_len = strlen((char *)plaintext); // длина текста
	unsigned char *key = (unsigned char *)"0123456789";// пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345";// инициализирующий вектор, рандомайзер
	unsigned char cryptedtext[256]; // зашифрованный результат
	unsigned char decryptedtext[256]; // расшифрованный результат

	EVP_CIPHER_CTX *ctx;//структура
	int len;
	fstream f0, f_encripted, f_decrypted;
	f0.open("plaintext.txt", std::fstream::in | std::fstream::binary);  //файл с исходными данными

										//файл для зашифрованых данных
	f_encripted.open("f_encripted.txt",
		std::fstream::out | std::fstream::trunc | std::fstream::binary);

	char buffer[256] = { 0 };
	char out_buf[256] = { 0 };

	ctx = EVP_CIPHER_CTX_new();
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	len = 0;
	f0.read(buffer, 256);
	while (f0.gcount() > 0)//цикл, пока из файла что то считывается(пока размер считаной функции >0)

	{
		// шифрование порции 
		// EVP_EncryptUpdate(ctx, // объект с настройками 
		//	(unsigned char *)out_buf, // входной параметр: ссылка, куда помещать зашифрованные данные 
		//	&len, // выходной параметр: длина полученного шифра 
		//	(unsigned char *)buffer, // входной параметр: что шифровать 
		//	f0.gcount()); // входной параметр : длина входных данных 
		EVP_EncryptUpdate(ctx, (unsigned char *)out_buf, &len, (unsigned char *)buffer, f0.gcount());
		// вывод зашифрованной порции в файл 
		f_encripted.write(out_buf, len);

		// считывание следующей порции 
		f0.read(buffer, 256);
	}
	EVP_EncryptFinal_ex(ctx, (unsigned char *)out_buf, &len);
	f_encripted.write(out_buf, len);
	f_encripted.close();
	f0.close();


	/* РАСШИФРОВАНИЕ */
	f_encripted.open("f_encripted.txt", std::fstream::in | std::fstream::binary);
	if (!(f_encripted.is_open()))
		return 0;

	f_decrypted.open("f_decrypted.txt",
		std::fstream::out | std::fstream::trunc | std::fstream::binary);



	ctx = EVP_CIPHER_CTX_new();
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	len = 0;
	f_encripted.read(out_buf, 256);
	while (f_encripted.gcount() > 0)//цикл, пока из файла что то считывается(пока размер считаной функции >0)

	{
		// шифрование порции 
		EVP_DecryptUpdate(ctx, // объект с настройками 
			(unsigned char *)buffer, // входной параметр: ссылка, куда помещать зашифрованные данные 
			&len, // выходной параметр: длина полученного шифра 
			(unsigned char *)out_buf, // входной параметр: что шифровать 
			f_encripted.gcount()); // входной параметр : длина входных данных 

						  // вывод зашифрованной порции в файл 
		f_decrypted.write(buffer, len);

		// считывание следующей порции 
		f_encripted.read(out_buf, 256);
	}
	EVP_DecryptFinal_ex(ctx, (unsigned char *)buffer, &len);
	f_decrypted.write(buffer, len);
	f_decrypted.close();
	f_encripted.close();

	system("Pause");
	return 0;
}