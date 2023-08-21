#include "main.hpp"
#include "Input.hpp"
#include "Draw.hpp"
#include "Cell.hpp"

int WIDTH = 1280, HEIGHT = 720;

sf::RenderWindow* win;
sf::View cam;

sf::Vector2i lastMpos;
sf::Vector2i mpos;
bool panning = false;
sf::Clock frametime;
float dt;
float sens = 1000.f;

int main() {
	win = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Game of life", sf::Style::Default);
	cam = sf::View(sf::Vector2f{ 640.f, 360.f }, sf::Vector2f{ 1280, 720 });

	while (win->isOpen()) {
		dt = frametime.restart().asSeconds();
		sf::Event e;
		mpos = sf::Mouse::getPosition(*win);
		while (win->pollEvent(e)) {
			input(e);
		}
		draw();
	}
}