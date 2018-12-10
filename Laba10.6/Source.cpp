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

// ���������� OpenSSL (openssl.org) ������������ ������ ����������� (��. �������� ���. �� �����������) 

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	fstream first("plaintext.txt", ios::binary | ios::in);
	fstream second("cryptedtext.txt", ios::binary | ios::out | ios::in);
	fstream third("decrypted.txt", ios::binary | ios::out);

	// ������ � ��������������� OpenSSL: 
	// 1) �������� ������� � ����������� 
	// 2) ����������, ���������� 
	// 3) ����������� 
	// 4) � ����� ������������� ������ 

	// ��� �������, � ����������, ��������� ������������ ��� �������� ������ ������ 
	// �� ����� � ������� � �������������/������������ 
	struct name_of_my_struct // ������ ������ 
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
//		(unsigned char *)"EVP_EncryptUpdate() encrypts inl bytes from the buffer in and writes the encrypted version to out";// �������� ����� 
//	int plaintext_len = strlen((char *)plaintext); // ����� ������ 

	unsigned char plaintext[256 * 100] = {};
	unsigned char cryptedtext[256 * 100] = {}; // ������������� ��������� 
	unsigned char decryptedtext[256 * 100] = {}; // �������������� ��������� 

	unsigned char *key = (unsigned char *)"0123456789"; // ������ (����) 
	unsigned char *iv = (unsigned char *)"0123456789012345"; // ���������������� ������, ����������� 


	// 1. �������� ��������� �� �������������� ��������� 
	// ��������� - ��� ������ � C++, ������ � ������, �������� ���������� 
	EVP_CIPHER_CTX *ctx; // structure 

	// 2. ��� ��������� �������� ������ ��������� �������� (�����, ����, ������ ������������� � �.�.) 
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������ 

	// 3. ��������� EVP_CIPHER_CTX ����������� ����������� 
	EVP_EncryptInit_ex(ctx, // ������ �� ������/���������, ���� ��������� ��������� 
		EVP_aes_256_cbc(), // ������ �� ��������� ���� AES 256 (������� � ����������) 
		NULL,
		key, // ����/������/������ 
		iv); // ����������� (��������� ��������� ������) 

	//��������� ������ (2 ��) � �������� ������

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

	//���������{
		//� 1-�� ����
		// 4. ��� ������� ���������� - ������� EVP_EncryptUpdate 
		int len;
		int cryptedtext_len = 0;
		for (int i = 0; i < razmer; i++)
		{
			EVP_EncryptUpdate(ctx, // ������ � ����������� 
				cryptedtext, // ������� ��������: ������, ���� �������� ������������� ������ 
				&len, // �������� ��������: ����� ����������� ����� 
				plaintext, // ������� ��������: ��� ��������� 
				plaintext_len); // ������� �������� : ����� ������� ������ 
			cryptedtext_len = len;
			//������ �� 2-�� ����
		//����� ����� }	
		}


		// 5. ����������� �������� ���������� 
		// ����������, ���� ��������� ���� �������� ������� �� ��������� 
		EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	// �������� � ���� ��������� ������ � ������� 
		cryptedtext_len += len;
		cout << "����� ����������� �����" << cryptedtext_len << endl;
		cout << "����� ���������" << plaintext<< endl;
		cout << "����� ����������� �����" << cryptedtext_len << endl;


		second.write((char*)&cryptedtext, sizeof(cryptedtext));
		cout << "������������� �����"<< endl;
		// 6. �������� ��������� 
		EVP_CIPHER_CTX_free(ctx);

		// ����� ������������� ������ 
		for (int i = 0; i < cryptedtext_len; i++)
		{
			cout << hex << cryptedtext[i];
			if ((i + 1) % 32 == 0) cout << endl;
		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	// ����������� 

	// 1. 
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������ 

	// 2. 
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // ������������� ������� AES, ������ � �������� 

	// 3. 
	EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len); // ����������, ���������� 

	// 4. 
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

	// 5. 
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	cout << decryptedtext << endl;

	// �- ���������� ����� 
	// ������������ ����� ��� ��, �� ��������, � ����� 
	// � ����� 
	/*
	1) �������� ������ � ��������� ���������� OpenSSL
	2) ���������� ������� �����
	3) while(���������_�������� > 0)
	{
	4) ���������� ����������
	5) ������ �������������� ������� � ����
	6) ���������� ���������� ���������
	}
	7)

	���������� �������������� �������
	8) ������ ��������������� ����� � ����
	9) �������� ������
	*/
	getchar();
	return 0;
}