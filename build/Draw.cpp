#include "Draw.hpp"
#include "Cell.hpp"

void draw() {
	win->clear(sf::Color::Black);
	win->setView(cam);
	for (Cell& cell : cells)
		cell.draw(0);
	win->display();
}