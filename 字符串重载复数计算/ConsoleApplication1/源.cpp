#include<iostream>
using namespace std;
class complex
{
public:
	complex(){}
	complex(int r,int i)
	{
		this->a = r;
		this->b = i;
	}
	void disp()
	{
		cout<< a << "+" << b << "i" << endl;
	}
	complex operator+(complex c2)
	{
		int a = this->a + c2.a;
		int b = this->b + c2.b;
		complex c3(a, b);
		return c3;
	}
	complex operator-(complex c2)
	{
		int a = this->a - c2.a;
		int b = this->b - c2.b;
		complex c3(a, b);
		return c3;
	}
	complex operator*(complex c2)
	{
		int a = (this->a*c2.a - this->b*c2.b);
		int b = (this->a*c2.a + this->a*c2.b);
		complex c3(a, b);
		return c3;
	}
	complex operator/(complex c2)
	{
		int a = (this->b*c2.a - this->a*c2.b) / (c2.a*c2.a + c2.b*c2.b);
		int b = (this->a*c2.a + this->b*c2.b) / (c2.a*c2.a + c2.b*c2.b);
		complex c3(a, b);
		return c3;
	}
	complex operator=(complex c2)
	{
		int a = this->a / (c2.a*c2.a + c2.b*c2.b);
		int b = this->b / (c2.a*c2.a + c2.b*c2.b);
		complex c3(a, b);
		return c3;
	}

private:
	int a;
	int b;
};
void main()
{
	complex c1(10, 10);
	complex c2(1, 3);
	complex c3 = c1 + c2;
	complex c4 = c1 - c2;
	complex c5 = c1 * c2;
	complex c6 = c1 / c2;
	complex c7 = c5 = c2;
	c1.disp();
	c2.disp();
	c3.disp();
	c4.disp();
	c5.disp();
	c6.disp();
	c7.disp();
}