#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Listener.hpp>
#include <SFML/Audio.hpp>
#include "options.h"
#include <time.h>
#include <list>
using namespace sf;

void menu(RenderWindow & window)
{
    Font font;//шрифт
    font.loadFromFile("font.ttf");//передаем нашему шрифту файл шрифта
    Text namegame("", font, 70);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
    namegame.setColor(Color::White);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
    namegame.setStyle(sf::Text::Bold);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
    Texture menuTexture1, menuTexture2, menuTexture3, optionTexture, menuBackground, menuLogo;
    menuTexture1.loadFromFile("images/start_game2.png");
    menuTexture2.loadFromFile("images/options2.png");
    menuTexture3.loadFromFile("images/exit_game2.png");
    menuBackground.loadFromFile("images/background1.jpg");
    //menuLogo.loadFromFile("images/logo2.png");
    Music music;//создаем объект музыки
    music.openFromFile("1.ogg");//загружаем файл
    music.play();//воспроизводим музыку
    Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), option(optionTexture), menuBg(menuBackground), menuLg(menuLogo);
    bool isMenu = 1;
    int menuNum = 0;
    menu1.setPosition(700, 280);
    menu2.setPosition(920, 450);
    menu3.setPosition(700, 520);
    menuBg.setPosition(0, 0);
    menuLg.setPosition(500, 250);
    namegame.setString("OSA  Pre-Alpha");//задает строку тексту
    namegame.setPosition(500 , 100 );//задаем позицию текста, центр камеры
//////////////////////////////МЕНЮ///////////////////
    while (isMenu)
    {
        menu1.setColor(Color::White);
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221));
        if (IntRect(1000, 250, 600, 150).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Yellow); menuNum = 1; }
        if (IntRect(1000, 450, 600, 150).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Yellow); menuNum = 2; }
        if (IntRect(1000, 650, 600, 150).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Yellow); menuNum = 3; }
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню
            if (menuNum == 2)
            {
                options(menuBg, window, font);
            }
        if (menuNum == 3)  { window.close(); isMenu = false; }
        }
    window.draw(menuBg);
    window.draw(menu1);
    window.draw(menu2);
    window.draw(menu3);
    window.draw(menuLg);
    window.draw(namegame);//рисую этот текст
    window.display();
    }
}
