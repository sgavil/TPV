#pragma once
#include "PacmanObject.h"
#include "Texture.h"
#include "SDL.h"
#include "checkML.h"

class PlayState;

// Tipos de celda para el mapa
enum mapCell { Empty, Wall, Food, Vitamins };


const int NUM_MAP_TEXTURES = 4; // Casilla vac�a, Muro, Comida, Vitamina

const int maxR = 50;
const int maxC = 50;
/*
Clase GameMap: crea la matriz, a partir de la cual se crear� y actualizar� el nivel

- Crea la matriz din�mica de celdas.
- Crea sus texturas est�ticas.
- Se comunica con <Game> -> Indica, actualiza, etc., sus celdas

*/

class Pacman;

class GameMap : public PacmanObject
{
private:
	SDL_Rect destRect;

	// Matriz din�mica de celdas
	mapCell **map = nullptr;

	// Array de texturas del mapa
	Texture* textures[NUM_MAP_TEXTURES];

	// Filas y columnas del mapa
	int rows, cols;
	
public:
	GameMap(PlayState*game);

	 void loadFromFile(ifstream& file);
	 void saveToFile(ofstream& file);

	 void render(SDL_Renderer* renderer);
	 void update();

	 mapCell getCell(int posX, int posY) const;
	 void setCell(int posX, int posY, mapCell cellKind);
	
	
	~GameMap();
};

