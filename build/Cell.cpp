#include "Cell.hpp"

int cellSize = HEIGHT / 32;

Cell::Cell(float x, float y) : isAlive(true) {
	rect.setSize(sf::Vector2f(cellSize, cellSize));
	rect.setPosition(sf::Vector2f(cellSize * (int)(x / cellSize), cellSize * (int)(y / cellSize)));
	rect.setFillColor(sf::Color::White);
}

Cell::Cell(sf::Vector2f pos) : isAlive(true) {
	rect.setSize(sf::Vector2f(cellSize, cellSize));
	rect.setPosition(sf::Vector2f(cellSize * (int)(pos.x / cellSize), cellSize * (int)(pos.y / cellSize)));
	rect.setFillColor(sf::Color::White);
}

void Cell::draw()
{
	win->draw(rect);
}

void Cell::update()
{
}

std::vector<Cell> cells;

void removeCell(int index)
{
	auto it = cells.begin();
	std::advance(it, index);
	cells.erase(it);
}