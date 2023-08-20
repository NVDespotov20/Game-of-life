#include "Draw.hpp"

void draw() {
	win->clear(sf::Color::Black);
	win->setView(cam);

	win->draw(circle);
	win->display();
}