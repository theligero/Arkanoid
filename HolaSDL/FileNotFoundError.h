#ifndef FILENOTFOUNDERROR_H_
#define FILENOTFOUNDERROR_H_

#include "ArkanoidError.h"

class FileNotFoundError : public ArkanoidError
{
public:
	FileNotFoundError(std::string file) : 
		ArkanoidError("Archivo " + file + " no encontrado.") {}
};

#endif