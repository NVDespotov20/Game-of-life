#include "Input.hpp"
#include <algorithm>
#include "Cell.hpp"
sf::Clock clickTime;
void input(sf::Event& e)
{
	if (e.type == sf::Event::MouseMoved){
		auto coords = win->mapPixelToCoords(sf::Mouse::getPosition(*win));
		printf("Mouse: %f, %f\n", coords.x, coords.y);
	}

	if (e.type == sf::Event::Closed)
		win->close();
	if (e.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !panning) {
		lastMpos = mpos;
		mpos = sf::Mouse::getPosition(*win);
		panning = true;
		clickTime.restart();
	}
	if (e.type == sf::Event::MouseButtonReleased && !sf::Mouse::isButtonPressed(sf::Mouse::Left) && panning) {
		bool onCell = false;
		int index = -1;
		for (Cell cell : cells) {
			++index;
			if (cell.rect.getGlobalBounds().contains(win->mapPixelToCoords(mpos)))
			{
				onCell = true;
				break;
			}
		}
		if (clickTime.getElapsedTime().asSeconds() < 0.1 && !onCell)
			cells.push_back(Cell{ win->mapPixelToCoords(mpos) });
		if (clickTime.getElapsedTime().asSeconds() < 0.1 && onCell)
			removeCell(index);
		panning = false;
	}

	if (panning) {
		cam.move(dt * (sf::Vector2f)(lastMpos - mpos) * sens);
		lastMpos = mpos;
	}

	if (e.type == sf::Event::MouseWheelMoved && e.mouseWheel.delta == -1) {
		cam.setSize(cam.getSize() * 1.1f);
		sens *= 1.1f;
	}
	else if (e.type == sf::Event::MouseWheelMoved && e.mouseWheel.delta == 1) {
		cam.setSize(cam.getSize() * .9f);
		sens *= .9f;
	}
}