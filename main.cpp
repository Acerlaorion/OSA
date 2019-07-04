#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Listener.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <list>
#include "menu.h"
#include <string>
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1920, 1080), "OSA Pre-Alpha");
    menu(window);
}
