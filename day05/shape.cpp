#include <iostream>
using namespace std;

class Shape
{
public:
	//virtual static void fun(){} //error
	virtual float area()
	{
		return -1;
	}
};

class Rectange: public Shape
{
public:
	Rectange(float h, float w)
	{
		m_fHeight = h;
		m_fWidth = w;
	}
	float area()
	{
		return m_fWidth * m_fHeight;
	}
private:
	float m_fHeight;
	float m_fWidth;
};

class Triangle: public Shape
{
public:
	Triangle(float b, float h)
	{
		m_fBottom = b;
		m_fHeight = h;
	}
	float area()
	{
		return m_fHeight * m_fBottom / 2;
	}
private:
	float m_fBottom;
	float m_fHeight;
};

class Circle: public Shape
{
public:
	Circle(float r)
	{
		m_fRadius = r;
	}
	float area()
	{
		return 3.14*m_fRadius*m_fRadius;
	}
private:
	float m_fRadius;
};

void getArea(Shape *shape)
{
	cout << shape->area() << endl;
}

int main(void)
{
	getArea(new Shape);
	getArea(new Rectange(3,4));
	getArea(new Triangle(3,4));
	getArea(new Circle(10));


	return 0;
}


