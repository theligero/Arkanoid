#include "Texture.h"
#include <iostream>

using namespace std;


void Texture::free() {
	SDL_DestroyTexture(texture);
	texture = nullptr;
	w = h = 0;
}

void Texture::load(string filename, uint nRows, uint nCols) { //Carga cada textura con su nombre de textura, su numero de filas y columnas. 
	std::string aux = "../images/";
	aux += filename;
	SDL_Surface* tempSurface = IMG_Load(aux.c_str());
	if (tempSurface == nullptr) throw "Error al cargar la superficie de " + filename;
	free();
	texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	if (texture == nullptr) throw "Error al cargar la textura " + filename;
	numRows = nRows;
	numCols = nCols;
	w = tempSurface->w;
	h = tempSurface->h;
	fw = w / numCols;
	fh = h / numRows;
	SDL_FreeSurface(tempSurface);
}

void Texture::render(const SDL_Rect& destRect, SDL_RendererFlip flip) const { //renderiza una textura completa.
	SDL_Rect srcRect;
	srcRect.x = 0; srcRect.y = 0;
	srcRect.w = w; srcRect.h = h;
	SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, 0, 0, flip);
}

void Texture::renderFrame(const SDL_Rect& destRect, int row, int col, int angle, SDL_RendererFlip flip) const { //Renderiza una parte(frame) de una textura. Pensada para spritesheets.
	SDL_Rect srcRect; //Establece el rectángulo de renderizado.
	srcRect.x = fw * col;
	srcRect.y = fh * row;
	srcRect.w = fw;
	srcRect.h = fh;
	SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, angle, 0, flip);
}