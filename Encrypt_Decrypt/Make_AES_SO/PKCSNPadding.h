#pragma once

#include <string.h>

void pkcs5Padding_encode(char* szDataIn, size_t strLen, int block_num, int block_size);
bool pkcs5Padding_decode(char *szDataOut, size_t strLen);

void pkcs7Padding_encode(char* szDataIn, size_t strLen, int block_num, int block_size);
bool pkcs7Padding_decode(char *szDataOut, size_t strLen);


