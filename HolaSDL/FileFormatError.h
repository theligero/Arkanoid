#ifndef FILEFORMATERROR_H_
#define FILEFORMATERROR_H_

#include "ArkanoidError.h"

class FileFormatError : public ArkanoidError
{
public:
	FileFormatError(std::string e) : ArkanoidError(e) {}
};

#endif