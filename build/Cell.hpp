#pragma once
#include "main.hpp"
class Cell {
public:
	Cell(float x,float y);
	Cell(sf::Vector2f pos);
	
	void draw();
	void update();

	bool isAlive;
	sf::RectangleShape rect;
};
extern std::vector<Cell> cells;
extern int cellSize;

void removeCell(int index);