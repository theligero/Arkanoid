#ifndef FILEFORMATERROR_H_
#define FILEFORMATERROR_H_

#include "ArkanoidError.h"

class FileFormatError : public ArkanoidError
{
public:
	FileFormatError(std::string error) : ArkanoidError(error) {}
	static std::string TamanoIncorrecto(int lvl) { return "Tamaño incorrecto del mapa " + std::to_string(lvl); }
	static std::string ValorDeColorIncorrecto(int col) { return "Se ha solicitado un color no válido"; }
};

#endif