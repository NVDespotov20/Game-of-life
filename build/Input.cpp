#include "Input.hpp"
void input(sf::Event &e)
{
	if (e.type == sf::Event::Closed)
		win->close();
	if (e.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !panning) {
		lastMpos = mpos;
		mpos = sf::Mouse::getPosition();
		panning = true;
	}
	if (e.type == sf::Event::MouseButtonReleased && !sf::Mouse::isButtonPressed(sf::Mouse::Left) && panning)
		panning = false;

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