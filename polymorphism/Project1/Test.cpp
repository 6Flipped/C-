#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	Person(const char* name)
		:_name(name)
	{}
	//�麯��
	virtual void BuyTicket()
	{
		cout << _name << " Person:ȫ�� 100" << endl;
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
	//�麯��+������/����/����-->��д/����
	virtual void BuyTicket()
	{
		cout << _name << " Student:��� 50" << endl;
	}
};

class Soldier :public Person {
public:
	Soldier(const char* name)
		:Person(name)
	{}
	//�麯��+������/����/����-->��д/����
	virtual void BuyTicket()
	{
		cout << _name << " Soldier:ȫ�� 100�������ȣ�" << endl;
	}
};

//��̬������Ҫ��
//1.�����麯����д�����麯������д����ͬ+�麯����
//2.�����Ǹ����ָ���������ȥ�����麯����

//ָ��
//void Pay(Person* ptr)
//{
//	ptr->BuyTicket();
//}

//����
//void Pay(Person& ptr)
//{
//	ptr.BuyTicket();
//}

//����-->���õ�ȫ�Ǹ���ĺ���
void Pay(Person ptr)
{
	ptr.BuyTicket();
}


int main()
{
	int option;
	do
	{
		cout << "��ѡ����ݣ�1.��ͨ�� 2.ѧ��  3.���ˣ�" << endl;
		cin >> option;
		cout << "���������֣�";
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
			cout << "�˳��ɹ���" << endl;
			break;
		default:
			cout << "�����������������" << endl;
			break;
		}
		cout << "===========================================" << endl;
	} while (option != -1);
	return 0;
}