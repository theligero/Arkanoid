#ifndef ARKANOIDERROR_H_
#define ARKANOIDERROR_H_

#include <stdexcept>
#include <string>

class ArkanoidError : public std::logic_error
{
public:
	ArkanoidError(std::string e) : std::logic_error(e.c_str()) {}
	std::string what() { return std::logic_error::what(); }
};

#endif