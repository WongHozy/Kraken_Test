#pragma once

#include "aes.h"
#include "base64.h"
#include "PKCSNPadding.h"

const char g_key[17] = "^%#q12.48W_rt:yS";
const char g_iv[17] = "5672368942738943";

std::string EncryptionAES(const std::string& strSrc);
std::string DecryptionAES(const std::string& strSrc);
