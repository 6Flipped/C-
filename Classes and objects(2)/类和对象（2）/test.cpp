
//		_month = month;
//		_day = day;
//	}
//	//基本没有自己重载的价值
//	//但也是默认重载
//	//除非你不想让别人获取Date类的地址信息
//	Date* operator&()
//	{
//		return this;
//	}
//	const Date* operator&() const
//	{
//		return this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};

//class Date
//{
//	friend istream& operator>>(istream& in, const Date& d);
//	friend ostream& operator<<(ostream& out, const Date& d);
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//cout<<d1;
//	//第一个参数是左操作数，第二个参数的右操作数
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//
//ostream& operator<<(ostream& out,const Date&d)
//{
//	out << d._year << "-" << d._month << "-" << d._day << endl;
//	return out;
//}
//
//istream& operator>>(istream& in, const Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
////extern ostream cout;
////extern istream cin;
//int main()
//{
//	Date d1,d2(2022,1,13);
//	cin >> d1;
//	cout << d1;
//	return 0;
//}

//int main()
//{
//
//	Date d1(2022, 1, 14);
//	Date d2(2022, 1, 13);
//	&d1;
//	&d2;
//
//	return 0;
//}

//class Date
//{
//public:
//	//可以理解成，一个对象的单个成员变量在初始化列表是它定义的阶段
//	//只能用初始化列表处理的变量
//	//1.const成员变量 2.引用类型 3.自定义类型成员（该类没有默认构造函数）
//	//尽量使用初始化列表，且声明和初始化的顺序一致
//	Date(int year = 0, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//	{
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	Date d2;
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};

//int main()
//{
//	A aa1(1);
//
//	//单参数的构造函数，支持类型转换
//	//早期编译器 A tmp(2)+A aa2(tmp)-->优化后直接调用构造函数
//	//语法意义上，先构造再拷贝构造
//	A aa2 = 2;
//
//	int i = 0;
//	const double& d = i;
//
//	string s1("hello");
//	string s2 = "hello";//
//	vector<string> v;
//	//string支持单参数的隐式类型转换，就可以这样
//	v.push_back(s1);
//	return 0;
//}

//int main()
//{
//	A aa1(1);//标准调用，定义有名对象
//	A aa2 = 2;//隐式类型转换，优化后也是调用构造函数
//	A(3);//构造匿名对象，生命周期在还在这一行
//	//什么场景使用：定义一个对象只有这一行用
//
//	return 0;
//}

class A
{
private:
	//这里只是声明，不存在构造函数初始化，在类外面全局位置初始化
	static int _n;//n是存在静态区，属于整个类，也属于类的所有对象
public:
	A()
	{
		++_n;
	}
	//区别在于没有this指针，不能访问非静态成员
	static int GetN()
	{
		return _n;
	}
};

//静态成员变量的初始化,不受访问限定符的限制
//类似于const不能修改，但需要初始化
int A::_n = 0;

int main()
{
	A a1;
	A a2;
	A();
	cout << a1.GetN() << endl;
	cout << A::GetN() << endl;

	return 0;
}