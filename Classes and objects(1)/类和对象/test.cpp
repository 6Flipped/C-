#include<iostream>
using namespace std;

//如何定义一个类
//封装
//1、将数据和方法放到定义一起
//2、把想给你看到的数据给你看看，不想给你看的封装起来-> 访问限定符

//
//class Stack {
//	//1.成员函数
//public:
//	void Push(int x)//类里面定义，里面声明
//	{
//		//...
//	}
//	void Pop();//类里面声明，类外面定义
//	bool Empty();
//	//...
//private:
//	//2.成员变量
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
////C语言中的struct是用来定义结构体的
////C++中，兼容C的struct定义结构体用法，但同时可以定义类
////C++中使用class和struct定义类的区别？-->默认的访问限定符
////class默认私有的，struct默认公有的
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
//	//还可以定义函数-》成员函数
//	ListNode_Cpp* CreatNode(int val);
//};
//
//void Stack::Pop()
//{
//	//...
//}

//1、声明和定义的区别？ 声明是一种承诺，承诺要干嘛，但是还没做，定义就是落实了

//int main()
//{
//	//类实例化出对象，相当于定义出了类的成员变量
//	/*Stack s1;
//	Stack s2;
//	Stack s3;
//	s1.Push(1);*/
//	//对象中只存储成员变量，不存储成员函数
//	//cout << sizeof(s1);
//	//一个类实例化出N个对象，每个对象的成员变量都可以存储不同的值，但调用的是同一个成员函数
//	//如果每个对象都放成员函数，而这些函数却是一样的，浪费空间
//
//	//如何计算一个类的实例化大小？-->只考虑成员变量之和，并考虑对齐
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
////内存对齐是必考
//int main()
//{
//	cout << sizeof(A1) << endl;
//	//没有成员变量的类的大小是1
//	//为什么是1而不是0
//	//开一个字节不是为了存数据，而是占位表示类存在
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3)<<endl;
//}

//实例化实际上就是用自己定义的类型定义出对象
//内置类型，基本类型 int/char/double
//自定义类型，class/struct

//访问限定符只限定类外部
//class Date 
//{
//public:
//	//this指针是谁调用这个函数就指向谁
//	//void Init(Date *this,int year, int month, int day)
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()//实际上编译器处理为void Print(Date *this)
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
////this指针存放在栈区,但在VS下存放在ecx寄存器中
//int main()
//{
//	//Date d1;
//	//d1.Init(2022, 1, 13);
//	//d1.Print();//谁调用成员函数，隐含的this指针就指向谁
//	A *p=nullptr;
//	p->PrintfA();//编译不通过还是报错-->崩溃
//	p->Show();//编译不通过还是报错-->正常运行
//	//为什么？
//	//函数存在公共代码段，所以都不会在p指向的空间去解引用
//	//访问成员变量是才回去找
//	return 0;
//}

//class Date 
//{
//public:
//	//构造函数->在对象构造是调用的函数，这个函数完成对象的初始化
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
//	void Print()//实际上编译器处理为void Print(Date *this)
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
//	//函数名和类名相同、无返回值、实例化时自动调用
//
//	Date d1(2022,1,13);
//	d1.Print();
//
//	Date d2;//不能加括号
//	d2.Print();
//
//
//
//	return 0;
//}

//如果类中没有显示定义的构造函数，编译器会自动生成默认无参数的构造函数
//默认生成无参构造函数
//针对自定义类型的成员变量，调用它的构造函数初始化
//针对内置类型，不做处理

//一旦显示定义了，编译器就不生成了
class Date
{
public:
	void Print()//实际上编译器处理为void Print(Date *this)
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
	Date d1;//不能加括号
	d1.Print();



	return 0;
}