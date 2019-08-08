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

bool selectLevel(RenderWindow & window, Music* music)
{
    setlocale(LC_ALL, "Russian");
    bool isSelect = 1;
    Event event;
    Font font;
    font.loadFromFile("9393.ttf");
    Text story("", font, 41);
    story.setColor(Color::White);
    Texture selectBackground, level1;
    selectBackground.loadFromFile("images/selectBg.jpg");
    level1.loadFromFile("images/level1.png");
    Sprite selectBg(selectBackground), lv1(level1);
    selectBg.setPosition(0, 0);
    lv1.setPosition(0, 0);
    story.setPosition(10, 130);
    while (!Keyboard::isKeyPressed(Keyboard::Escape) && (isSelect))
    {
        while (window.pollEvent(event))
        {
            window.clear(Color(129, 181, 221));
            lv1.setColor(Color::White);
            story.setString("");
            if (IntRect(1290, 136, 567, 119).contains(Mouse::getPosition(window)))
            {
                lv1.setColor(Color::Magenta);
                story.setString(" Локация 1- Локация,\n на которой происходит знакомство\n с Зазой(главным злодеем),\n проходит первый бой, и начинается сюжет.");
            }
            Vector2f mouse_world =  window.mapPixelToCoords(Mouse::getPosition(window));
            if (event.type == Event::Closed)
                window.close();
            if(event.type== Event::MouseButtonPressed)
            if (event.mouseButton.button == Mouse::Left)
            {
                //std::cout << mouse_world.x << std::endl;
                //std::cout << mouse_world.y << std::endl;
                if(((mouse_world.x>=1290)&&(mouse_world.x<=1857))&&((mouse_world.y>=136)&&(mouse_world.y<=255)))
                {
                    isSelect = 0;
                    if(Gameplay(window,music) == 1)
                        isSelect = 1;
                }
            }
            window.draw(selectBg);
            window.draw(lv1);
            window.draw(story);
            window.display();
        }
    }
    return true;
}

#endif // SELECTLEVEL_H_INCLUDED
