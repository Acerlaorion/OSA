#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Listener.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <string>
#include "menu.h"
using namespace sf;

int main()
{
    RenderWindow window;
    window.create(sf::VideoMode(1920, 1080), "OSA!", sf::Style::Fullscreen);//создание окна
    menu(window);
    return 0;
}
