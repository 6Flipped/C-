#include<iostream>
#include<string>
using namespace std;

//class A
//{
//public:
//	void fun()
//	{
//		cout << "A::func()" << endl;
//	}
//};
//
//class B :public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "B::func()" << endl;
//	}
//};
////此时A::func和B::func是隐藏关系
////重载必须在同一个作用域
//
//int main()
//{
//	B b;
//	//b.fun();//编译报错
//	//在继承中，不要定义同名的成员
//	b.fun(1);
//	return 0;	
//}

//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//public:
//	Student(const char* name="", int num=0)
//		:_num(num)
//		,Person(name)
//	{}
//
//	Student(const Student& s)
//		:Person(s)
//	{}
//
//protected:
//	int _num; //学号
//};


class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};
class Student : public Person
{
public:
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);
			_num = s._num;
		}
		return *this;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //学号
};

//子类构造函数原则：1、调用父类构造函数初始化继承自父类成员  
// 2.自己再初始化自己的成员--规则参考普通类
//析构，拷贝构造，复制重载也类似
int main()
{
	Student s();
	return 0;
}