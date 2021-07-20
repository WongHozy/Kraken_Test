#define _CRT_SECURE_NO_WARNINGS

#include "AES128_CBC_PKCS5Padding.h"

//AES加密
std::string EncryptionAES(const std::string& strSrc)
{
	size_t length = strSrc.length();
	int block_num = length / BLOCK_SIZE + 1;

	//明文
	char* szDataIn = new char[block_num * BLOCK_SIZE + 1];
	memset(szDataIn, 0x00, block_num * BLOCK_SIZE + 1);
	strcpy(szDataIn, strSrc.c_str());

	//进行PKCSNPadding填充
	pkcs7Padding_encode(szDataIn, length, block_num, BLOCK_SIZE);

	//加密后的密文
	char *szDataOut = new char[block_num * BLOCK_SIZE + 1];
	memset(szDataOut, 0, block_num * BLOCK_SIZE + 1);

	//进行进行AES的CBC模式加密
	AES aes;
	aes.MakeKey(g_key, g_iv, 16, BLOCK_SIZE);
	aes.Encrypt(szDataIn, szDataOut, block_num * BLOCK_SIZE, AES::CBC);
	std::string str = base64_encode((unsigned char*)szDataOut, block_num * BLOCK_SIZE);

	delete[] szDataIn;
	delete[] szDataOut;

	return str;
}

//AES解密
std::string DecryptionAES(const std::string& strSrc)
{
	std::string strData = base64_decode(strSrc);
	size_t length = strData.length();
	//密文
	char *szDataIn = new char[length + 1];
	memcpy(szDataIn, strData.c_str(), length + 1);
	//明文
	char *szDataOut = new char[length + 1];
	memcpy(szDataOut, strData.c_str(), length + 1);

	//进行AES的CBC模式解密
	AES aes;
	aes.MakeKey(g_key, g_iv, 16, 16);
	aes.Decrypt(szDataIn, szDataOut, length, AES::CBC);

	//去PKCS7Padding填充
	bool paddDecode = pkcs7Padding_decode(szDataOut, length);
	if (!paddDecode)
	{
		//cout << "去填充失败！解密出错！！" << endl;
	}

	std::string strDest(szDataOut);
	delete[] szDataIn;
	delete[] szDataOut;

	return strDest;
}

