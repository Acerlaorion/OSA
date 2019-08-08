#define SFML_NO_DEPRECATED_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Listener.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include <list>
#include <string>
#include <sstream>
#include "options.h"
#include "selectLevel.h"
using namespace sf;

void menu(RenderWindow & window)
{
    Font font;//шрифт
    font.loadFromFile("STALKERItalic.ttf");//передаем нашему шрифту файл шрифта
    Text namegame("", font, 70);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
    namegame.setColor(Color::White);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
    namegame.setStyle(sf::Text::Bold);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
    Texture menuTexture1, menuTexture2, menuTexture3, menuBackground, menuLogo, menuIcon1, menuIcon2, menuIcon3,
    menuIcon1Big, menuIcon2Big, menuIcon3Big, volon, voloff;
    Image iconwindow;
    iconwindow.loadFromFile("images/iconwindow.png");
    menuTexture1.loadFromFile("images/start_game4.png");
    menuTexture2.loadFromFile("images/options4.png");
    menuTexture3.loadFromFile("images/exit_game4.png");
    menuBackground.loadFromFile("images/background1.jpg");
    menuIcon1.loadFromFile("images/icon1.png");
    menuIcon2.loadFromFile("images/icon2.png");
    menuIcon3.loadFromFile("images/icon3.png");
    menuIcon1Big.loadFromFile("images/icon1big.png");
    menuIcon2Big.loadFromFile("images/icon2big.png");
    menuIcon3Big.loadFromFile("images/icon3big.png");
    menuLogo.loadFromFile("images/logo3.png");
    volon.loadFromFile("images/auon.png");
    voloff.loadFromFile("images/auoff.png");
    Music music;//создаем объект музыки
    music.openFromFile("1.ogg");//загружаем файл
    music.play();//воспроизводим музыку
    int VolumeMusic = 10;
    music.setVolume(10);
    Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menuBg(menuBackground), menuLg(menuLogo),
    icon1(menuIcon1), icon2(menuIcon2), icon3(menuIcon3), icon1Big(menuIcon1Big), icon2Big(menuIcon2Big), icon3Big(menuIcon3Big),
    von(volon), voff(voloff);
    bool isMenu = 1;
    int menuNum = 0;
    menu1.setPosition(-70, 1);
    icon1.setPosition(-100, 1);
    icon1Big.setPosition(-100, 1);
    menu2.setPosition(-70, 2);
    icon2.setPosition(-80, 2);
    icon2Big.setPosition(-80, 2);
    menu3.setPosition(-70, 3);
    icon3.setPosition(-100, 3);
    icon3Big.setPosition(-100, 3);
    menuBg.setPosition(0, 0);
    menuLg.setPosition(-70, 0);
    von.setPosition(300, -410);
    voff.setPosition(330, -410);
    namegame.setPosition(400 , 50 );//задаем позицию текста, центр камеры
    namegame.setString("OSA  Pre-Alpha");//задает строку тексту
    window.setIcon(32, 32, iconwindow.getPixelsPtr());
//////////////////////////////МЕНЮ///////////////////
    while (isMenu)
    {
        Event event;
        menu1.setColor(Color::White);
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221));
        if (IntRect(900, 225, 575, 125).contains(Mouse::getPosition(window)))
            {
                menu1.setColor(Color::Yellow);
                menuNum = 1;
                window.draw(menuBg);
                window.draw(menu1);
                window.draw(menu2);
                window.draw(icon2);
                window.draw(menu3);
                window.draw(icon3);
                window.draw(menuLg);
                window.draw(von);
                window.draw(voff);
                window.draw(icon1Big);
                window.draw(namegame);
                window.display();
            }
        if (IntRect(1000, 438, 508, 125).contains(Mouse::getPosition(window)))
            {
                 menu2.setColor(Color::Yellow);
                 menuNum = 2;
                window.draw(menuBg);
                window.draw(menu1);
                window.draw(icon1);
                window.draw(menu2);
                window.draw(menu3);
                window.draw(icon3);
                window.draw(menuLg);
                window.draw(von);
                window.draw(voff);
                window.draw(icon2Big);
                window.draw(namegame);;
                window.display();
            }
        if (IntRect(900, 658, 590, 120).contains(Mouse::getPosition(window)))
            {
                menu3.setColor(Color::Yellow);
                menuNum = 3;
                window.draw(menuBg);
                window.draw(menu1);
                window.draw(icon1);
                window.draw(menu2);
                window.draw(icon2);
                window.draw(menu3);
                window.draw(menuLg);
                window.draw(von);
                window.draw(voff);
                window.draw(icon3Big);
                window.draw(namegame);
                window.display();
            }
        Vector2f mouse_world =  window.mapPixelToCoords(Mouse::getPosition(window));
            while (window.pollEvent(event))
            {
                if(event.type == Event::Closed)
                    window.close();
                    if(event.type== Event::MouseButtonPressed)
                        if(event.mouseButton.button == Mouse::Left)
                        {
                            if(((mouse_world.x>=900)&&(mouse_world.x<=1475))&&((mouse_world.y>=225)&&(mouse_world.y<=350)))
                            {
                                isMenu = false;
                                menuNum = 0;

                                if (selectLevel(window,&music) == 1)
                                    isMenu = true;
                            }
                            if(((mouse_world.x>=950)&&(mouse_world.x<=1475))&&((mouse_world.y>=435)&&(mouse_world.y<=560)))
                            {
                                isMenu = false;
                               if(options(window, &VolumeMusic, &music) == 1)
                                    isMenu = true;
                            }

                            if(((mouse_world.x>=1000)&&(mouse_world.x<=1658))&&((mouse_world.y>=658)&&(mouse_world.y<=778)))
                            {
                                isMenu = false;
                                window.close();
                            }
                            if(((mouse_world.x>=1287)&&(mouse_world.x<=1403))&&((mouse_world.y>=93)&&(mouse_world.y<=182)))
                            {
                                music.play();
                            }
                            if(((mouse_world.x>=1461)&&(mouse_world.x<=1584))&&((mouse_world.y>=93)&&(mouse_world.y<=182)))
                            {
                                music.pause();
                            }
                        }
            }
    window.draw(menuBg);
    window.draw(menu1);
    window.draw(icon1);
    window.draw(menu2);
    window.draw(icon2);
    window.draw(menu3);
    window.draw(icon3);
    window.draw(menuLg);
    window.draw(von);
    window.draw(voff);
    window.draw(namegame);
    window.display();
    }
}
