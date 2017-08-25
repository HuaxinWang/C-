#include <iostream>
#include <unistd.h>
using namespace std;

class Time
{
public:
	Time(int minute = 0, int second = 0)
	{
		m_iMinute = minute;
		m_iSecond = second;
	}
	void display()
	{
		cout << m_iMinute << ':' << m_iSecond
			 << endl;	
	}

	Time operator++()
	{
		cout << "Time operator++()\n";
		m_iSecond++;
		if (60 == m_iSecond)
		{
			m_iSecond = 0;
			m_iMinute++;
			if (60 == m_iMinute)
			{
				m_iMinute = 0;
			}
		}
		return *this;		
	}
	Time operator++(int)
	{
		Time t = *this;
		m_iSecond++;
		if (60 == m_iSecond)
		{
			m_iSecond = 0;
			m_iMinute++;
			if (60 == m_iMinute)
			{
				m_iMinute = 0;
			}
		}
		return t;
	}
	
	Time operator--()
	{
		cout << "Time operator--()\n";
		if (0 == m_iSecond)
		{
			m_iSecond = 59;
			if (0 == m_iMinute)
			{
				m_iMinute = 59;
			}
			else
			{
				m_iMinute--;
			}
		}
		else
		{
			m_iSecond--;
		}
		return *this;		
	}
	Time operator--(int)
	{
		Time t = *this;
		if (0 == m_iSecond)
		{
			m_iSecond = 59;
			if (0 == m_iMinute)
			{
				m_iMinute = 59;
			}
			else
			{
				m_iMinute--;
			}
		}
		else
		{
			m_iSecond--;
		}
		return t;
	}

private:
	int m_iMinute;
	int m_iSecond;
};

int main(void)
{
	Time  t(59, 56);
	t.display();

	//Time t2 = --t;
	Time t2 = t--;
	t.display();
	t2.display();

	Time t3(0, 6);
	while (1)
	{
		t3.display();
		--t3;
		sleep(1);
	}

#if 0
	Time t2 = t++;
	t.display();
	t2.display();
#endif
#if 0
	Time t2 = ++t;  //t++
	t.display();
	t2.display();

	while (1)
	{
		++t;
		t.display();
		sleep(1);
	}
#endif

	return 0;
}
