#pragma once

//TODO: NAMESPACES!!!
#include <vector>
#include <string>
typedef unsigned char BYTE;

std::string base64_encode(std::vector<unsigned char> buffer, unsigned int bufLen);
std::vector<BYTE> base64_decode(std::string const&);
