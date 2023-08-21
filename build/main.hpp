#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

extern int WIDTH, HEIGHT;

extern sf::RenderWindow *win;
extern sf::View cam;
 
extern sf::Vector2i lastMpos;
extern sf::Vector2i mpos;
extern bool panning;
extern sf::Clock frametime;
extern float dt;
extern float sens;