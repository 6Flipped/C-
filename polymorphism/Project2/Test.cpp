#include<iostream>
using namespace std;


//class Car
//{
//public:
//	virtual void Drive() final{}
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz--舒服" << endl;
//	}
//};


//final修饰类不能被继承
//final修饰函数不能被重写
class Car
{
public:
	void Drive()
	{
	}
private:
	Car()
	{}
};

//override严格检查是否重写，写在子类
class Benz :public Car
{
public:
	void Drive() override
	{
		cout << "Benz--舒服" << endl;
	}
};

int main()
{
	return 0;
}