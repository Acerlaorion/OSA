#ifndef SELECTLEVEL_H_INCLUDED
#define SELECTLEVEL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Listener.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include <list>
#include <string>
#include "Gameplay.h"
#include <sstream>

using namespace sf;

bool selectLevel(RenderWindow & window)
{
    bool isSelect = 1;
    Event event;
    Texture selectBackground, level1;
    selectBackground.loadFromFile("images/selectBg.jpg");
    level1.loadFromFile("images/level1.png");
    Sprite selectBg(selectBackground), lv1(level1);
    selectBg.setPosition(0, 0);
    lv1.setPosition(0, 0);
    while (!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        while (window.pollEvent(event))
        {
            window.clear(Color(129, 181, 221));
            Vector2f mouse_world =  window.mapPixelToCoords(Mouse::getPosition(window));
            if (event.type == Event::Closed)
                window.close();
            if(event.type== Event::MouseButtonPressed)
            if (event.mouseButton.button == Mouse::Left)
            {
                *HP=100000;
                Gameplay();

            }
            window.draw(selectBg);
            window.draw(lv1);
            window.display();
        }
    }
    return true;
}

#endif // SELECTLEVEL_H_INCLUDED
