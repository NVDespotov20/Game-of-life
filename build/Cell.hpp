#pragma once
#include "main.hpp"
class Cell {
public:
	Cell();
	Cell(float x,float y);
	Cell(sf::Vector2f pos);
	
	void draw(bool drallCheckZone);
	int getNeighbours();

	bool isAlive;
	sf::RectangleShape rect;
	sf::RectangleShape checkzone;
};
extern std::vector<Cell> cells;
extern int cellSize;

void removeCell(int index);
void spawnCell(int i, int j, std::vector<Cell> &newCells);
bool shouldSpawnCell(sf::Vector2f pos, std::vector<Cell>& newCells);