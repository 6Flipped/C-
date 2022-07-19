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
////��ʱA::func��B::func�����ع�ϵ
////���ر�����ͬһ��������
//
//int main()
//{
//	B b;
//	//b.fun();//���뱨��
//	//�ڼ̳��У���Ҫ����ͬ���ĳ�Ա
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
//	string _name; // ����
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
//	int _num; //ѧ��
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
	string _name; // ����
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
	int _num; //ѧ��
};

//���๹�캯��ԭ��1�����ø��๹�캯����ʼ���̳��Ը����Ա  
// 2.�Լ��ٳ�ʼ���Լ��ĳ�Ա--����ο���ͨ��
//�������������죬��������Ҳ����
int main()
{
	Student s();
	return 0;
}