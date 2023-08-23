#include "Update.hpp"
#include "Cell.hpp"

void update()
{
	std::vector<int> neighbours;
	for (int i = 0; i < cells.size(); ++i) {
		neighbours.push_back(cells[i].getNeighbours());
		
	}
	
	std::vector<Cell> newCells;
	for (int i = 0; i < cells.size(); ++i)
		for (int j = 0; j < cells.size(); ++j) {
			if (i == j)
				continue;
			spawnCell(i, j, newCells);
		}
	for (Cell cell : newCells)
		cells.push_back(cell);
	for (int i = neighbours.size()-1; i >= 0; --i) {
		if (neighbours[i] < 2 || neighbours[i] > 3)
			removeCell(i);
	}
}