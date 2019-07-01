#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>
#include <iostream>
using namespace sf;

const int W = 1900;
const int H = 1070;

float DEGTORAD = 0.017453f;

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
    float x,y,R;
    bool life;
    std::string name;
    Animation anim;

    Entity()
    {
      life=1;
    }

    void settings(Animation &a,int X,int Y,int radius=1)
    {
      anim = a;
      x=X; y=Y;
      R = radius;
    }

    virtual void update(){};

    void draw(RenderWindow &app)
    {
      anim.sprite.setPosition(x,y);
      app.draw(anim.sprite);
      CircleShape circle(R);
      circle.setFillColor(Color(255,0,0,170));
      circle.setPosition(x,y);
      circle.setOrigin(R,R);
      app.draw(circle);
    }

    virtual ~Entity(){};
};


class asteroid: public Entity
{
public:
  asteroid()
  {
    //dx=rand()%8-4;
   // dy=rand()%8-4;
    name="asteroid";
  }
void  update()
  {
      if (x>W) x=0;  if (x<0) x=W;
   if (y>H) y=0;  if (y<0) y=H;
  }

};
int main()
{
    int sc =0;
    int *score = &sc;

    srand(time(0));

    RenderWindow app(VideoMode(W, H), "OSU!");
    app.setFramerateLimit(60);

    Texture t2,t4,t5,t6,t7;
    t2.loadFromFile("images/background.jpg");
    t4.loadFromFile("images/rock.png");
    t5.loadFromFile("images/fire_blue.png");
    t6.loadFromFile("images/rock_small.png");
    t7.loadFromFile("images/explosions/type_B.png");
    t2.setSmooth(true);
    Sprite background(t2);

    Animation sRock(t4, 0,0,64,64, 16 );
    Animation sRock_small(t6, 0,0,64,64, 16 );
    Animation sExplosion_ship(t7, 0,0,192,192, 64);


    std::vector<Entity*> entities;

    for(int i=0;i<15;i++)
    {
      asteroid *a = new asteroid();
      a->settings(sRock, rand()%W, rand()%H, 25);
      entities.push_back(a);
    }

    /////main loop/////
    while (app.isOpen())
    {
            Event event;
        for(auto e:entities)
         if (e->name=="explosion")
          if (e->anim.isEnd()) e->life=0;

        for(auto i=entities.begin();i!=entities.end();)
        {
          Entity *e = *i;
          e->update();
          e->anim.update();
          if (e->life==false) {i=entities.erase(i); delete e;}
          else i++;
        }
        float x;
        std::ostringstream playerScoreString;
        Vector2f mouse_world =  app.mapPixelToCoords(Mouse::getPosition( app ) );
        while (app.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    app.close();
                    if(event.type== Event::MouseButtonPressed)
                        if (event.mouseButton.button == Mouse::Left)
                        {
                            for(int i =0;i<entities.size();i++)
                            if((mouse_world.x>=(entities[0]->x)-10)&&(mouse_world.x<=(entities[0]->x)+10))
                            {
                                std::cout << "YPA";break;
                            }


                            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                            sc++;
                            playerScoreString <<*score ;

                        }
            }

        Font font;//�����
        font.loadFromFile("ALGER.TTF");//�������� ������ ������ ���� ������
        Text text("", font, 20);//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
        text.setColor(Color::Red);//��������� ����� � �������. ���� ������ ��� ������, �� �� ��������� �� �����
        text.setStyle(Text::Bold);//������ �����.
       //////draw//////
       app.draw(background);
            // �������� ����������
        for(auto i:entities)
        {
        text.setString("SCORE:");//������ ������ ������ � �������� �������������� ���� ������ ������� .str()
        text.setPosition(100,200);//������ ������� ������, �������� �� ������ ������
        app.draw(text);//����� ���� �����
        text.setString(playerScoreString.str());
        text.setPosition(180,200);//������ ������� ������, �������� �� ������ ������
        app.draw(text);//����� ���� �����
         i->draw(app);
        }

       app.display();
    }

    return 0;
}
