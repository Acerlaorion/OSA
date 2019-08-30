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
    namegame.setColor(Color::White);//покрасили текст в белый.
    namegame.setStyle(sf::Text::Bold);//жирный текст. по умолчанию он "худой":)) и не подчеркнутый
    Texture menuTexture1, menuTexture2, menuTexture3, menuBackground, menuLogo, menuIcon1, menuIcon2, menuIcon3,
    menuIcon1Big, menuIcon2Big, menuIcon3Big, volon, voloff; // делаем переменные текстуры
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
    voloff.loadFromFile("images/auoff.png"); // загружаем картинки из папки
    Music music;//создаем объект музыки
    music.openFromFile("1.ogg");//загружаем музыку
    music.play();//воспроизводим музыку
    int VolumeMusic = 10; // переменная громкости музыки
    music.setVolume(10); // устанавливает значение на 10 громкости
    Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menuBg(menuBackground), menuLg(menuLogo),
    icon1(menuIcon1), icon2(menuIcon2), icon3(menuIcon3), icon1Big(menuIcon1Big), icon2Big(menuIcon2Big), icon3Big(menuIcon3Big),
    von(volon), voff(voloff); // делаем из текстур спрайты
    bool isMenu = 1; // переменная активности меню
    int menuNum = 0; // изначально ни одна из клавиш меню не выбрана, для удобства
    menu1.setPosition(-70, 1);
    icon1.setPosition(-100, 1);
    icon1Big.setPosition(-100.1, 1);
    menu2.setPosition(-70, 2);
    icon2.setPosition(-80, 2);
    icon2Big.setPosition(-80.1, 2);
    menu3.setPosition(-70, 3);
    icon3.setPosition(-100, 3);
    icon3Big.setPosition(-100.1, 3);
    menuBg.setPosition(0, 0);
    menuLg.setPosition(-70, 0);
    von.setPosition(300, -410);
    voff.setPosition(330, -410); // задаем позицию спрайтов
    namegame.setPosition(400 , 50 );//задаем позицию текста, центр камеры
    namegame.setString("OSA");//задает строку тексту
    window.setIcon(32, 32, iconwindow.getPixelsPtr()); // иконка приложения
    bool icon1_Big, icon2_Big, icon3_Big; // переменные для увелечения иконки при наведении мышкой на клавиши в меню
    Color colorArray[7] = {Color::White, Color::Red, Color::Green, Color::Blue, Color::Magenta, Color::Cyan, Color::Yellow}; // массив цветов
//////////////////////////////МЕНЮ///////////////////
    while (isMenu) // цикл меню
    {
        Event event;
        menu1.setColor(Color::White);
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221)); // очищаем окно
        icon1_Big = false; icon2_Big = false; icon3_Big = false; // изначально устанавливаем, что большие иконки не активны
        if (IntRect(900, 225, 575, 125).contains(Mouse::getPosition(window))) // если мышка наведена на определённый участок координат
            {
                icon1_Big = true; // то большая иконка становится активной
                menu1.setColor(Color::Yellow); // клавиша старта красится в жёлтый цвет
                menuNum = 1; // выбрана 1 клавиша в меню - "играть"
            }
        if (IntRect(1000, 438, 508, 125).contains(Mouse::getPosition(window))) // аналогично с 1-ым условием; 2 клавиша - выход
            {
                icon2_Big = true;
                 menu2.setColor(Color::Yellow);
                 menuNum = 2;
            }
        if (IntRect(900, 658, 590, 120).contains(Mouse::getPosition(window))) // аналогично с 1-ым условием; 3 клавиша - выход
            {
                icon3_Big = true;
                menu3.setColor(Color::Yellow);
                menuNum = 3;
            }
        Vector2f mouse_world =  window.mapPixelToCoords(Mouse::getPosition(window)); // передаёт координаты с мышки
            while (window.pollEvent(event))
            {
                if(event.type == Event::Closed) // если закрыть окно
                    window.close(); // окно закроется :)
                    if(event.type== Event::MouseButtonPressed) // условие нажатия на мышку
                        if(event.mouseButton.button == Mouse::Left) // если нажата ЛКМ
                        {
                            if(((mouse_world.x>=900)&&(mouse_world.x<=1475))&&((mouse_world.y>=225)&&(mouse_world.y<=350))) // нажимаем на 1 клавишу мышкой по заданным координатам
                            {
                                isMenu = false; // меню становится неактивно
                                if (selectLevel(window,&music) == 1) // передаём следующую функцию с выбором уровней, и ждём пока она не завершится. Передаём в неё окно и указатель на музыку
                                    isMenu = true; // функция выбора уровня завершена. Становится активно меню
                            }
                            if(((mouse_world.x>=950)&&(mouse_world.x<=1475))&&((mouse_world.y>=435)&&(mouse_world.y<=560))) // аналогично для 2 клавиши
                            {
                                isMenu = false;
                               if(options(window, &VolumeMusic, &music) == 1) // передаём функцию с настройками и также ждём
                                    isMenu = true;
                            }

                            if(((mouse_world.x>=1000)&&(mouse_world.x<=1658))&&((mouse_world.y>=658)&&(mouse_world.y<=778))) // клавиша выхода
                            {
                                isMenu = false; // меню неактивно
                                window.close(); // окно закрывается
                            }
                            if(((mouse_world.x>=1287)&&(mouse_world.x<=1403))&&((mouse_world.y>=93)&&(mouse_world.y<=182)))
                            {
                                music.play(); // старт / начало музыки
                            }
                            if(((mouse_world.x>=1461)&&(mouse_world.x<=1584))&&((mouse_world.y>=93)&&(mouse_world.y<=182)))
                            {
                                music.pause(); // остановка музыки
                            }
                            if(((mouse_world.x>=345)&&(mouse_world.x<=885))&&((mouse_world.y>=350)&&(mouse_world.y<=655)))
                            {
                                menuLg.setColor(colorArray[rand()%7]); // "пасхалка", если нажмём на логотип в меню, то он будет окрашен в рандомный цвет :D
                            }
                        }
            }
    window.draw(menuBg); // отрисовка заднего фона
    window.draw(menu1); // ниже описано отрисовка всех спрайтов
    if (!icon1_Big) // если большая иконка не активна, то отрисовываем маленькую
        window.draw(icon1);
    if (icon1_Big) // если большая иконка активна, то отрисовывем её, аналогично представлено с другими иконками ниже
        window.draw(icon1Big);
    window.draw(menu2);
    if (!icon2_Big)
        window.draw(icon2);
    if (icon2_Big)
        window.draw(icon2Big);
    window.draw(menu3);
    if (!icon3_Big)
        window.draw(icon3);
    if (icon3_Big)
        window.draw(icon3Big);
    window.draw(menuLg); // отрисовка логотипа
    window.draw(von); // отрисовка старта музыки
    window.draw(voff); // отрисовка приглушения музыки
    window.draw(namegame); // отрисовка названия игры
    window.display(); // обновление экрана
    }
}
