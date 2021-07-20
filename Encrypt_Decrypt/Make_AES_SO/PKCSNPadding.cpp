#include "PKCSNPadding.h"

void pkcs5Padding_encode(char* szDataIn, size_t strLen, int block_num, int block_size)
{
	int padding = block_size - (strLen % block_size);

	if (padding == 0)
	{
		padding == block_size;
	}

	for (size_t i = 0; i < padding; i++)
	{
		szDataIn[strLen + i] = padding;
	}
	szDataIn[strLen + padding] = '\0';
}

bool pkcs5Padding_decode(char *szDataOut, size_t strLen)
{
	return false;
}


/*
 * 在PKCS5Padding定义中,Block的大小是8字节,如果已经是8的整数倍,则填充8个0x08.
 * 在PKCS7Padding定义中,Block的大小是不确定的,可以在1-255之间,填充值算法与PKCS5Padding一样.
 * 因为AES加密算法的Block大小是16字节,所以填充Block的大小必须为16字节.
 */
void pkcs7Padding_encode(char* szDataIn, size_t strLen, int block_num, int block_size)
{
	int k = strLen % block_size;
	int j = strLen / block_size;
	int padding = block_size - k;
	for (int i = 0; i < padding; i++)
	{
		szDataIn[j * block_size + k + i] = padding;
	}
	szDataIn[block_num * block_size] = '\0';
}

bool pkcs7Padding_decode(char *szDataOut, size_t strLen)
{
	if (0x00 < szDataOut[strLen - 1] <= 0x16)
	{
		int tmp = szDataOut[strLen - 1];
		for (int i = strLen - 1; i >= strLen - tmp; i--)
		{
			if (szDataOut[i] != tmp)
			{
				memset(szDataOut, 0, strLen);
				//cout << "去填充失败！解密出错！！" << endl;
				return false;
			}
			else
				szDataOut[i] = 0;
		}
	}

	return true;
}
