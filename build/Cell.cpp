#include "Cell.hpp"

int cellSize = HEIGHT / 32;

Cell::Cell() : isAlive(true) {
	rect.setSize(sf::Vector2f(cellSize, cellSize));
	rect.setFillColor(sf::Color::Red);
	checkzone.setSize(sf::Vector2f(cellSize * 3, cellSize * 3));
	checkzone.setFillColor(sf::Color::Yellow);
}

Cell::Cell(float x, float y) : isAlive(true) {
	rect.setSize(sf::Vector2f(cellSize, cellSize));
	rect.setPosition(sf::Vector2f(cellSize * (int)(x / cellSize), cellSize * (int)(y / cellSize)));
	rect.setFillColor(sf::Color::White);
	checkzone.setSize(sf::Vector2f(cellSize * 3, cellSize * 3));
	checkzone.setPosition(rect.getPosition() - sf::Vector2f(cellSize, cellSize));
	checkzone.setFillColor(sf::Color::Green);
}

Cell::Cell(sf::Vector2f pos) : isAlive(true) {
	rect.setSize(sf::Vector2f(cellSize, cellSize));
	rect.setPosition(sf::Vector2f(cellSize * (int)(pos.x / cellSize), cellSize * (int)(pos.y / cellSize)));
	rect.setFillColor(sf::Color::White);
	checkzone.setSize(sf::Vector2f(cellSize * 3, cellSize * 3));
	checkzone.setPosition(rect.getPosition() - sf::Vector2f(cellSize, cellSize));
	checkzone.setFillColor(sf::Color::Green);
}

void Cell::draw(bool drallCheckZone)
{	if(drallCheckZone)
		win->draw(checkzone);
	win->draw(rect);
}

int Cell::getNeighbours()
{
	int neighbours = 0;
	sf::Vector2f cellPos = rect.getGlobalBounds().getPosition();
	for (Cell& cell : cells) {
		if (this == &cell)
			continue;
		if (checkzone.getGlobalBounds().intersects(cell.rect.getGlobalBounds()))
			++neighbours;
	}
	return neighbours;
}

std::vector<Cell> cells;

void removeCell(int index)
{
	auto it = cells.begin();
	std::advance(it, index);
	cells.erase(it);
}

bool emptySpace(sf::Vector2f pos, std::vector<Cell>* newCells = nullptr)
{
	for (Cell& cell : cells)
		if (cell.rect.getPosition() == pos)
			return false;
	if(newCells == nullptr)
		return true;
	for (Cell& cell : *newCells)
		if (cell.rect.getPosition() == pos)
			return false;
	return true;
}

void spawnCell(int i, int j, std::vector<Cell> &newCells)
{
	sf::Vector2f points[8] = {
		cells[i].rect.getPosition() + sf::Vector2f(-cellSize,-cellSize),	//top left
		cells[i].rect.getPosition() + sf::Vector2f(0,-cellSize),			//top center
		cells[i].rect.getPosition() + sf::Vector2f(cellSize,-cellSize),		//top right			# # #
		cells[i].rect.getPosition() + sf::Vector2f(cellSize,0),				//right				# C #
		cells[i].rect.getPosition() + sf::Vector2f(cellSize,cellSize),		//down right		# # #
		cells[i].rect.getPosition() + sf::Vector2f(0,cellSize),				//down center
		cells[i].rect.getPosition() + sf::Vector2f(-cellSize,cellSize),		//down left
		cells[i].rect.getPosition() + sf::Vector2f(-cellSize,0),			//left
	};
	for (int k = 0; k < 8; ++k)
		if (cells[j].checkzone.getGlobalBounds().contains(points[k]) && shouldSpawnCell(points[k], newCells))
			newCells.push_back(Cell(points[k]));
}

bool shouldSpawnCell(sf::Vector2f pos, std::vector<Cell> &newCells)
{
	if (!emptySpace(pos, &newCells))
		return false;

	Cell temp(pos);
	int n = temp.getNeighbours();
	return n == 3;
}
