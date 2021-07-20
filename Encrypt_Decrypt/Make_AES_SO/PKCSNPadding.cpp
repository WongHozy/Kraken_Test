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
 * ��PKCS5Padding������,Block�Ĵ�С��8�ֽ�,����Ѿ���8��������,�����8��0x08.
 * ��PKCS7Padding������,Block�Ĵ�С�ǲ�ȷ����,������1-255֮��,���ֵ�㷨��PKCS5Paddingһ��.
 * ��ΪAES�����㷨��Block��С��16�ֽ�,�������Block�Ĵ�С����Ϊ16�ֽ�.
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
				//cout << "ȥ���ʧ�ܣ����ܳ�����" << endl;
				return false;
			}
			else
				szDataOut[i] = 0;
		}
	}

	return true;
}
