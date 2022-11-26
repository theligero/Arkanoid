#ifndef SDLERROR_H_
#define SDLERROR_H_

#include "ArkanoidError.h"
#include <SDL_error.h>

class SDLError : public ArkanoidError
{
public:
	SDLError(std::string error) : 
		ArkanoidError(error) {}
};

#endif