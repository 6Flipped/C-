#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	Person(const char* name)
		:_name(name)
	{}
	//虚函数
	virtual void BuyTicket()
	{
		cout << _name << " Person:全价 100" << endl;
	}
protected:
	string _name;
	//int _id;
};

class Student :public Person {
public:
	Student(const char* name)
		:Person(name)
	{}
	//虚函数+函数名/参数/返回-->重写/覆盖
	virtual void BuyTicket()
	{
		cout << _name << " Student:半价 50" << endl;
	}
};

class Soldier :public Person {
public:
	Soldier(const char* name)
		:Person(name)
	{}
	//虚函数+函数名/参数/返回-->重写/覆盖
	virtual void BuyTicket()
	{
		cout << _name << " Soldier:全价 100（可优先）" << endl;
	}
};

//多态的两个要求
//1.子类虚函数重写父类虚函数（重写：三同+虚函数）
//2.必须是父类的指针或者引用去调用虚函数。

//指针
//void Pay(Person* ptr)
//{
//	ptr->BuyTicket();
//}

//引用
//void Pay(Person& ptr)
//{
//	ptr.BuyTicket();
//}

//对象-->调用的全是父类的函数
void Pay(Person ptr)
{
	ptr.BuyTicket();
}


int main()
{
	int option;
	do
	{
		cout << "请选择身份：1.普通人 2.学生  3.军人：" << endl;
		cin >> option;
		cout << "请输入名字：";
		string name;
		cin >> name;
		switch (option)
		{
		case 1:
		{
			Person p(name.c_str());
			Pay(p);
			break; 
		}
		case 2:
		{
			Student st(name.c_str());
			Pay(st);
			break; 
		}
		case 3:
		{
			Soldier so(name.c_str());
			Pay(so);
			break; 
		}
		case -1:
			cout << "退出成功！" << endl;
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}
		cout << "===========================================" << endl;
	} while (option != -1);
	return 0;
}