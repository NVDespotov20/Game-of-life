#include "main.hpp"
#include "Input.hpp"
#include "Draw.hpp"

sf::RenderWindow* win;
sf::View cam;

sf::CircleShape circle;

sf::Vector2i lastMpos;
sf::Vector2i mpos;
bool panning = false;
sf::Clock frametime;
float dt;
float sens = 1000.f;


int main() {
	win = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game of life", sf::Style::Default);
	cam = sf::View(sf::Vector2f{ 640.f, 360.f }, sf::Vector2f{ 1280, 720 });
	circle.setRadius(100.f);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(640, 360);
	
	while (win->isOpen()) {
		dt = frametime.restart().asSeconds();
		sf::Event e;
		mpos = sf::Mouse::getPosition();
		while (win->pollEvent(e)) {
			input(e);
		}
		draw();
	}
}