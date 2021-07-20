#include <iostream>
#include "Make_AES_SO/AES128_CBC_PKCS5Padding.h"

int main()
{
	string str1 = "qwertyuisfdlsajdxcvnkhsakfh13324878";
	cout << "EncryptionAES Before:" << str1 << endl;

	string str2 = EncryptionAES(str1);
	cout << "EncryptionAES  After:" << str2 << endl;

	string str3 = DecryptionAES(str2);
	cout << "DecryptionAES  After:" << str3 << endl;

	return 0;
}
