#include<iostream>
using namespace std;

//��ζ���һ����
//��װ
//1�������ݺͷ����ŵ�����һ��
//2��������㿴�������ݸ��㿴����������㿴�ķ�װ����-> �����޶���

//
//class Stack {
//	//1.��Ա����
//public:
//	void Push(int x)//�����涨�壬��������
//	{
//		//...
//	}
//	void Pop();//�����������������涨��
//	bool Empty();
//	//...
//private:
//	//2.��Ա����
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
////C�����е�struct����������ṹ���
////C++�У�����C��struct����ṹ���÷�����ͬʱ���Զ�����
////C++��ʹ��class��struct�����������-->Ĭ�ϵķ����޶���
////classĬ��˽�еģ�structĬ�Ϲ��е�
//
//struct ListNode_C
//{
//	int _val;
//	struct ListNode_C* _next;
//	struct ListNode_C* _prev;
//};
//
//struct ListNode_Cpp
//{
//	int _val;
//	struct ListNode_Cpp* _next;
//	struct ListNode_Cpp* _prev;
//	//�����Զ��庯��-����Ա����
//	ListNode_Cpp* CreatNode(int val);
//};
//
//void Stack::Pop()
//{
//	//...
//}

//1�������Ͷ�������� ������һ�ֳ�ŵ����ŵҪ������ǻ�û�������������ʵ��

//int main()
//{
//	//��ʵ�����������൱�ڶ��������ĳ�Ա����
//	/*Stack s1;
//	Stack s2;
//	Stack s3;
//	s1.Push(1);*/
//	//������ֻ�洢��Ա���������洢��Ա����
//	//cout << sizeof(s1);
//	//һ����ʵ������N������ÿ������ĳ�Ա���������Դ洢��ͬ��ֵ�������õ���ͬһ����Ա����
//	//���ÿ�����󶼷ų�Ա����������Щ����ȴ��һ���ģ��˷ѿռ�
//
//	//��μ���һ�����ʵ������С��-->ֻ���ǳ�Ա����֮�ͣ������Ƕ���
//
//	return 0;
//}

//class A1 {
//public:
//	void f1(){}
//private:
//	int _a;
//	char _ch;
//};
//
//class A2 {
//public:
//	void f2(){}
//};
//
//class A3 {
//
//};
//
////�ڴ�����Ǳؿ�
//int main()
//{
//	cout << sizeof(A1) << endl;
//	//û�г�Ա��������Ĵ�С��1
//	//Ϊʲô��1������0
//	//��һ���ֽڲ���Ϊ�˴����ݣ�����ռλ��ʾ�����
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3)<<endl;
//}

//ʵ����ʵ���Ͼ������Լ���������Ͷ��������
//�������ͣ��������� int/char/double
//�Զ������ͣ�class/struct

//�����޶���ֻ�޶����ⲿ
//class Date 
//{
//public:
//	//thisָ����˭�������������ָ��˭
//	//void Init(Date *this,int year, int month, int day)
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()//ʵ���ϱ���������Ϊvoid Print(Date *this)
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class A
//{
//public:
//	void PrintfA()
//	{
//		cout << _a << endl;
//	}
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
////thisָ������ջ��,����VS�´����ecx�Ĵ�����
//int main()
//{
//	//Date d1;
//	//d1.Init(2022, 1, 13);
//	//d1.Print();//˭���ó�Ա������������thisָ���ָ��˭
//	A *p=nullptr;
//	p->PrintfA();//���벻ͨ�����Ǳ���-->����
//	p->Show();//���벻ͨ�����Ǳ���-->��������
//	//Ϊʲô��
//	//�������ڹ�������Σ����Զ�������pָ��Ŀռ�ȥ������
//	//���ʳ�Ա�����ǲŻ�ȥ��
//	return 0;
//}

//class Date 
//{
//public:
//	//���캯��->�ڶ������ǵ��õĺ��������������ɶ���ĳ�ʼ��
//	/*Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}*/
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()//ʵ���ϱ���������Ϊvoid Print(Date *this)
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//��������������ͬ���޷���ֵ��ʵ����ʱ�Զ�����
//
//	Date d1(2022,1,13);
//	d1.Print();
//
//	Date d2;//���ܼ�����
//	d2.Print();
//
//
//
//	return 0;
//}

//�������û����ʾ����Ĺ��캯�������������Զ�����Ĭ���޲����Ĺ��캯��
//Ĭ�������޲ι��캯��
//����Զ������͵ĳ�Ա�������������Ĺ��캯����ʼ��
//����������ͣ���������

//һ����ʾ�����ˣ��������Ͳ�������
class Date
{
public:
	void Print()//ʵ���ϱ���������Ϊvoid Print(Date *this)
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;//���ܼ�����
	d1.Print();



	return 0;
}