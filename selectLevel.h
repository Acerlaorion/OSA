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
#include "Gameplay2.h"
#include "Gameplay3.h"
#include "Gameplay4.h"
#include "Gameplay5.h"
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
    Text back_("BACK", font, 128);
    back_.setStyle(sf::Text::Italic);
    story.setColor(Color::White);
    back_.setColor(Color::White);
    Texture selectBackground, level1, level2, level3, level4, level5;
    selectBackground.loadFromFile("images/selectBg.jpg");
    level1.loadFromFile("images/level1.png");
    level2.loadFromFile("images/level2.png");
    level3.loadFromFile("images/level3.png");
    level4.loadFromFile("images/level4.png");
    level5.loadFromFile("images/level5.png");
    Sprite selectBg(selectBackground), lv1(level1), lv2(level2), lv3(level3), lv4(level4), lv5(level5);
    selectBg.setPosition(0, 0);
    lv1.setPosition(0, 0);
    lv2.setPosition(0, 0);
    lv3.setPosition(0, 0);
    lv4.setPosition(0, 0);
    lv5.setPosition(0, 0);
    story.setPosition(10, 130);
    back_.setPosition(832, 840);
    while (!Keyboard::isKeyPressed(Keyboard::Escape) && (isSelect))
    {
        while (window.pollEvent(event))
        {
            window.clear(Color(129, 181, 221));
            back_.setRotation(0);
            lv1.setColor(Color::White);
            lv2.setColor(Color::White);
            lv3.setColor(Color::White);
            lv4.setColor(Color::White);
            lv5.setColor(Color::White);
            story.setString("");
            if (IntRect(1290, 130, 567, 120).contains(Mouse::getPosition(window)))
            {
                lv1.setColor(Color::Magenta);
                story.setString(" Локация 1- Локация,\n на которой происходит знакомство\n с Зазой(главным злодеем),\n проходит первый бой, и начинается сюжет.");
            }
            if (IntRect(1290, 260, 567, 120).contains(Mouse::getPosition(window)))
            {
                lv2.setColor(Color::Magenta);
                story.setString(" Локация 2- Локация,\n на которой происходит сражение\n с пауком (помощницей Зазы),\n сюжет продолжается.");
            }
            if (IntRect(1290, 384, 567, 120).contains(Mouse::getPosition(window)))
            {
                lv3.setColor(Color::Magenta);
                story.setString(" Локация 3- Локация,\n на которой происходит сражение\n с комаром (помощницей Зазы),\n сюжет продолжается.");
            }
            if (IntRect(1290, 520, 567, 120).contains(Mouse::getPosition(window)))
            {
                lv4.setColor(Color::Magenta);
                story.setString(" Локация 4- Локация,\n на которой происходит сражение\n с муравьем (помощницей Зазы),\n сюжет продолжается.");
            }
            if (IntRect(1290, 650, 567, 120).contains(Mouse::getPosition(window)))
            {
                lv5.setColor(Color::Magenta);
                story.setString(" Локация 5- Локация,\n на которой происходит финальное\n сражение с Зазой , главный герой\n побеждает противника и возвращает\n чувство ритма, сюжет завершается.");
            }
            if (IntRect(830, 860, 215, 90).contains(Mouse::getPosition(window))) { back_.setRotation(2); }
            Vector2f mouse_world =  window.mapPixelToCoords(Mouse::getPosition(window));
            if (event.type == Event::Closed)
                window.close();
            if(event.type== Event::MouseButtonPressed)
            if (event.mouseButton.button == Mouse::Left)
            {
                if(((mouse_world.x>=1290)&&(mouse_world.x<=1857))&&((mouse_world.y>=136)&&(mouse_world.y<=255)))
                {
                    isSelect = 0;
                    if(Gameplay(window, music) == 1) // активируется функция с геймплеем
                        isSelect = 1;
                }
                if(((mouse_world.x>=1290)&&(mouse_world.x<=1857))&&((mouse_world.y>=280)&&(mouse_world.y<=385)))
                {
                    isSelect = 0;
                    if(Gameplay2(window, music) == 1)
                        isSelect = 1;
                }
                if(((mouse_world.x>=1290)&&(mouse_world.x<=1857))&&((mouse_world.y>=404)&&(mouse_world.y<=515)))
                {
                    isSelect = 0;
                    if(Gameplay3(window, music) == 1)
                        isSelect = 1;
                }
                if(((mouse_world.x>=1290)&&(mouse_world.x<=1857))&&((mouse_world.y>=540)&&(mouse_world.y<=655)))
                {
                    isSelect = 0;
                    if(Gameplay4(window, music) == 1)
                        isSelect = 1;
                }
                if(((mouse_world.x>=1290)&&(mouse_world.x<=1857))&&((mouse_world.y>=630)&&(mouse_world.y<=795)))
                {
                    isSelect = 0;
                    if(Gameplay5(window, music) == 1)
                        isSelect = 1;
                }
                if (((mouse_world.x>=830)&&(mouse_world.x<=1045)&&(mouse_world.y>=860)&&(mouse_world.y<=950)))
                {
                    isSelect = 0; // переменная выхода из выбора уровней
                }
            }
            window.draw(selectBg);
            window.draw(lv1);
            window.draw(lv2);
            window.draw(lv3);
            window.draw(lv4);
            window.draw(lv5);
            window.draw(story);
            window.draw(back_);
            window.display();
        }
    }
    return true;
}

#endif // SELECTLEVEL_H_INCLUDED
