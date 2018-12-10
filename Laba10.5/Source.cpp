#include <iostream>
#include <sstream>

#include "sha.h"

using namespace std;

string to_hex(unsigned char s) {
	stringstream ss;
	ss << hex << (int)s;
	return ss.str();
}

string sha256(string line) {
	unsigned char hash[SHA256_DIGEST_LENGTH];
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, line.c_str(), line.length());
	SHA256_Final(hash, &sha256);

	string output = "";
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
		output += to_hex(hash[i]);
	}
	return output;
}

int main() {
	cout << sha256("hello, world") << endl;

	system("Pause");
	return 0;
}