
//		_month = month;
//		_day = day;
//	}
//	//����û���Լ����صļ�ֵ
//	//��Ҳ��Ĭ������
//	//�����㲻���ñ��˻�ȡDate��ĵ�ַ��Ϣ
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
//	//��һ������������������ڶ����������Ҳ�����
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
//	//�������ɣ�һ������ĵ�����Ա�����ڳ�ʼ���б���������Ľ׶�
//	//ֻ���ó�ʼ���б���ı���
//	//1.const��Ա���� 2.�������� 3.�Զ������ͳ�Ա������û��Ĭ�Ϲ��캯����
//	//����ʹ�ó�ʼ���б��������ͳ�ʼ����˳��һ��
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
//	//�������Ĺ��캯����֧������ת��
//	//���ڱ����� A tmp(2)+A aa2(tmp)-->�Ż���ֱ�ӵ��ù��캯��
//	//�﷨�����ϣ��ȹ����ٿ�������
//	A aa2 = 2;
//
//	int i = 0;
//	const double& d = i;
//
//	string s1("hello");
//	string s2 = "hello";//
//	vector<string> v;
//	//string֧�ֵ���������ʽ����ת�����Ϳ�������
//	v.push_back(s1);
//	return 0;
//}

//int main()
//{
//	A aa1(1);//��׼���ã�������������
//	A aa2 = 2;//��ʽ����ת�����Ż���Ҳ�ǵ��ù��캯��
//	A(3);//���������������������ڻ�����һ��
//	//ʲô����ʹ�ã�����һ������ֻ����һ����
//
//	return 0;
//}

class A
{
private:
	//����ֻ�������������ڹ��캯����ʼ������������ȫ��λ�ó�ʼ��
	static int _n;//n�Ǵ��ھ�̬�������������࣬Ҳ����������ж���
public:
	A()
	{
		++_n;
	}
	//��������û��thisָ�룬���ܷ��ʷǾ�̬��Ա
	static int GetN()
	{
		return _n;
	}
};

//��̬��Ա�����ĳ�ʼ��,���ܷ����޶���������
//������const�����޸ģ�����Ҫ��ʼ��
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