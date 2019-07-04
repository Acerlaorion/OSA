

using namespace sf;

class LifeBar
{
public:
	Image image;
	Texture t;
	Sprite s;
	int max;
	RectangleShape bar;

	LifeBar()
	{
		image.loadFromFile("images/life.png");
		image.createMaskFromColor(Color(50, 96, 166));
		t.loadFromImage(image);
		s.setTexture(t);
		s.setTextureRect(IntRect(0, 0, 552, 49));
		bar.setFillColor(Color(0, 0, 0));//������ ������������� ������������� ������ � ���������� ������ ���������� ��������
		max = 100000;
	}

	void update(int k)// k-������� ��������
	{
		if (k>0)
		if (k<max)
			bar.setSize(Vector2f(((k-max) * 550 / max),49));//���� �� ������������ � ��� ���� ������ ���������, �� ������������� ����� �������� (����� ������) ��� ������� ��������������
	}

	void draw(RenderWindow &window)
	{
		Vector2f center = window.getView().getCenter();
		Vector2f size = window.getView().getSize();
		s.setPosition(center.x - size.x / 2 , center.y - size.y / 2 );//������� �� ������
		bar.setPosition(center.x - size.x / 2+552 , center.y - size.y / 2 );

		window.draw(s);//������� ������ ������� ��������
		window.draw(bar);//������ �� ��� ������ �������������, �� ��� �� ��������� �
	}

};
