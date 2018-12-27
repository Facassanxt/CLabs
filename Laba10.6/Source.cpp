#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
//#include "stdafx.h" 
#include <iostream> 
#include <conf.h> // �������, ��������� � ��������� ��������� OpenSSL 
#include <conf.h> 
#include <evp.h> // ���� ���������������� ������� https://wiki.openssl.org/index.php/EVP 
#include <err.h> // ���� ���������� ������ OpenSSL � �� ����������� 
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
// ���������� OpenSSL (openssl.org) ������������ ������ ����������� (��. �������� ���. �� �����������)

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	unsigned char *plaintext = (unsigned char *)"";// �������� �����
	int plaintext_len = strlen((char *)plaintext); // ����� ������
	unsigned char *key = (unsigned char *)"0123456789";// ������ (����)
	unsigned char *iv = (unsigned char *)"0123456789012345";// ���������������� ������, �����������
	unsigned char cryptedtext[256]; // ������������� ���������
	unsigned char decryptedtext[256]; // �������������� ���������

	EVP_CIPHER_CTX *ctx;//���������
	int len;
	fstream f0, f_encripted, f_decrypted;
	f0.open("plaintext.txt", std::fstream::in | std::fstream::binary);  //���� � ��������� �������

										//���� ��� ������������ ������
	f_encripted.open("f_encripted.txt",
		std::fstream::out | std::fstream::trunc | std::fstream::binary);

	char buffer[256] = { 0 };
	char out_buf[256] = { 0 };

	ctx = EVP_CIPHER_CTX_new();
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	len = 0;
	f0.read(buffer, 256);
	while (f0.gcount() > 0)//����, ���� �� ����� ��� �� �����������(���� ������ �������� ������� >0)

	{
		// ���������� ������ 
		// EVP_EncryptUpdate(ctx, // ������ � ����������� 
		//	(unsigned char *)out_buf, // ������� ��������: ������, ���� �������� ������������� ������ 
		//	&len, // �������� ��������: ����� ����������� ����� 
		//	(unsigned char *)buffer, // ������� ��������: ��� ��������� 
		//	f0.gcount()); // ������� �������� : ����� ������� ������ 
		EVP_EncryptUpdate(ctx, (unsigned char *)out_buf, &len, (unsigned char *)buffer, f0.gcount());
		// ����� ������������� ������ � ���� 
		f_encripted.write(out_buf, len);

		// ���������� ��������� ������ 
		f0.read(buffer, 256);
	}
	EVP_EncryptFinal_ex(ctx, (unsigned char *)out_buf, &len);
	f_encripted.write(out_buf, len);
	f_encripted.close();
	f0.close();


	/* ������������� */
	f_encripted.open("f_encripted.txt", std::fstream::in | std::fstream::binary);
	if (!(f_encripted.is_open()))
		return 0;

	f_decrypted.open("f_decrypted.txt",
		std::fstream::out | std::fstream::trunc | std::fstream::binary);



	ctx = EVP_CIPHER_CTX_new();
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	len = 0;
	f_encripted.read(out_buf, 256);
	while (f_encripted.gcount() > 0)//����, ���� �� ����� ��� �� �����������(���� ������ �������� ������� >0)

	{
		// ���������� ������ 
		EVP_DecryptUpdate(ctx, // ������ � ����������� 
			(unsigned char *)buffer, // ������� ��������: ������, ���� �������� ������������� ������ 
			&len, // �������� ��������: ����� ����������� ����� 
			(unsigned char *)out_buf, // ������� ��������: ��� ��������� 
			f_encripted.gcount()); // ������� �������� : ����� ������� ������ 

						  // ����� ������������� ������ � ���� 
		f_decrypted.write(buffer, len);

		// ���������� ��������� ������ 
		f_encripted.read(out_buf, 256);
	}
	EVP_DecryptFinal_ex(ctx, (unsigned char *)buffer, &len);
	f_decrypted.write(buffer, len);
	f_decrypted.close();
	f_encripted.close();

	system("Pause");
	return 0;
}