#include <iostream>
using namespace std;

class Shape
{
public:
	//纯虚函数
	//含有纯虚函数的类称之为抽象类
	//抽象类不能定义对象
	//若其派生类中没有对该纯虚函数重新定义
	//则派生类仍然为抽象类，不能定义对象

	//若派生类想要生成对象，则必须在派生类中
	//对纯虚函数进行定义
	virtual float area() = 0;
};

class Test:public Shape
{};

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
//	Test t;
//	getArea(new Shape);
	getArea(new Rectange(3,4));
	getArea(new Triangle(3,4));
	getArea(new Circle(10));


	return 0;
}


