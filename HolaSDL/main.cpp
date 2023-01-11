#include "Game.h"
#include "checkML.h"
#include "ArkanoidError.h"
#include <iostream>

int main(int argc, char* argv[]){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	try {
		Game juego;
		juego.run();
	}
	catch (ArkanoidError error) { std::cout << error.what() << std::endl; }
	return 0;
}