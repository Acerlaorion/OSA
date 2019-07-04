#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <sstream>
#include "hp.h"
#include "life.h"
#include <iostream>
using namespace sf;
Clock clock1;
const int W = 1920;
const int H = 1080;
int hp =100000;
int *HP = &hp;

class Animation
{
public:
	float Frame;
	Sprite sprite;
    std::vector<IntRect> frames;

	Animation(){}

    Animation (Texture &t, int x, int y, int w, int h, int count)
	{
	    Frame = 0;

		for (int i=0;i<count;i++)
         frames.push_back( IntRect(x+i*w, y, w, h)  );

		sprite.setTexture(t);
		sprite.setOrigin(w/2,h/2);
        sprite.setTextureRect(frames[0]);
	}


	void update()
	{
		int n = frames.size();
		if (Frame >= n) Frame -= n;
		if (n>0) sprite.setTextureRect( frames[int(Frame)] );
	}

	bool isEnd()
	{
	  return Frame>=frames.size();
	}

};


class Entity
{
public:
float x,y,t;
bool life;
std::string name;
Animation anim;

Entity()
{
  life=1;
  t=clock1.getElapsedTime().asMilliseconds();;
}

void settings(Animation &a,int X,int Y)
{
  anim = a;
  x=X; y=Y;
}

virtual void update(){};

void draw(RenderWindow &app)
{
  anim.sprite.setPosition(x,y);
  app.draw(anim.sprite);
}

virtual ~Entity(){};
};


class asteroid: public Entity
{
public:
  asteroid()
  {
    name="asteroid";
  }

void  update()
  {
   if (x>W) x=10;  if (x<0) x=W;
   if (y>H) y=10;  if (y<0) y=H;
  }

};
void Gameplay()
{

    int sc =0;
    int *score = &sc;
    srand(time(0));
    RenderWindow app(VideoMode(W, H), "OSA!");
    app.setFramerateLimit(60);
    Texture t1,t2,t4;
    t2.loadFromFile("images/BG.jpg");
    t4.loadFromFile("images/rock.png");
    t1.setSmooth(true);
    t2.setSmooth(true);
    Sprite background(t2);
    Animation sRock(t4, 0,0,64,64, 16);
    std::list<Entity*> entities;
    int w,h;
    w=W-200;
    h=H-200;

    /////main loop/////
    while (app.isOpen())
    {
        while(*HP>0)
        {


        Vector2f mouse_world =  app.mapPixelToCoords(Mouse::getPosition( app ) );
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            if ((event.mouseButton.button == Mouse::Left)||(Keyboard::isKeyPressed(Keyboard::Z))||(Keyboard::isKeyPressed(Keyboard::X))||(Keyboard::isKeyPressed(Keyboard::Left))||(Keyboard::isKeyPressed(Keyboard::Down)))
                            {
                                std::cout<< "x=" << mouse_world.x << std::endl;
                                std::cout<< "y=" << mouse_world.y << std::endl;
                                for(auto a:entities)
                                if(((mouse_world.x>=(a->x)-40)&&(mouse_world.x<=(a->x)+40))&&((mouse_world.y>=(a->y)-40)&&(mouse_world.y<=(a->y)+40)))
                                {

                                    a->life=false;
                                    sc+=10000;
                                    hplife(HP);
                                }
                            }
        }
        float cloker = clock1.getElapsedTime().asMilliseconds();
    if (rand()%150==0)
     {

       asteroid *a = new asteroid();
       a->settings(sRock, 200 + rand()%(1000 - 200),200 + rand()%(1000 - 200));
       entities.push_back(a);
     }

    for(auto i=entities.begin();i!=entities.end();)
    {
      Entity *e = *i;
      e->update();
      e->anim.update();
      if((cloker-3000)>(e->t)) {e->life=false;}
      if (e->life==false) {i=entities.erase(i); delete e; hpdrainmiss(HP);}
      else i++;
    }

   //////draw//////
   app.draw(background);

   for(auto i:entities)
     i->draw(app);
            std::ostringstream playerScoreString;
            Font font;//шрифт
            font.loadFromFile("ALGER.TTF");//передаем нашему шрифту файл шрифта
            Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
            text.setColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
            text.setStyle(Text::Bold);//жирный текст.
            text.setString("SCORE:");//задаем строку тексту и вызываем сформированную выше строку методом .str()
            text.setPosition(1750,0);//задаем позицию текста, отступая от центра камеры
            app.pushGLStates();
            app.draw(text);//рисую этот текст
            app.popGLStates();
            Text text2("", font, 20);
            playerScoreString <<*score ;
            text2.setString(playerScoreString.str());
            text2.setPosition(1825,0);//задаем позицию текста, отступая от центра камеры
            app.pushGLStates();
            app.draw(text2);//рисую этот текст
            app.popGLStates();



    LifeBar lifeBarPlayer;
    lifeBarPlayer.update(*HP);
    hpdraintime(HP);
    lifeBarPlayer.draw(app);
    app.display();
    }
    app.close();
    }


}
