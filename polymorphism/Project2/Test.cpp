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
//		cout << "Benz--���" << endl;
//	}
//};


//final�����಻�ܱ��̳�
//final���κ������ܱ���д
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

//override�ϸ����Ƿ���д��д������
class Benz :public Car
{
public:
	void Drive() override
	{
		cout << "Benz--���" << endl;
	}
};

int main()
{
	return 0;
}