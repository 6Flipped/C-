#include<iostream>
#include<string>

using namespace std;
#include"string.h"

//template<class T>
//class basic_string
//{
//private:
//	T* str;
//	//......
//};
//
////����--ֵ--���Ž���ӳ���ϵ--�����
////ascii�����--��ʾӢ��
////unicode -- ��ʾȫ�������ֱ����  utf-8
////gbk -- �����Լ��������ı����
//int main()
//{
//	//string s1("hello");
//	char str1[] = "hello";
//
//	return 0;
//}


//int main()
//{
//	string s1;
//	string s2("hello world");
//	string s3(s2);
//	cout << s1 << endl << s2 << endl << s3 << endl;
//	
//	
//	string s4(s2, 2, 6);
//	cout << s4 << endl;
//
//	//nposΪstring�еľ�̬������һ��Ϊ-1
//	string s5(s2, 2);
//	cout << s5 << endl;
//
//	string s6(s2, 2, 100);
//	cout << s6 << endl;
//
//	string s7("hello",7);
//	cout << s7 << endl;
//
//
//	return 0;
//}

//int main()
//{
//	string s1("hello");
//	//�����������Ϊ��β��ʶ����\0����Ч�ַ�������
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.max_size() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1 << endl;
//	s1.clear();
//	cout << s1 << endl;
//	cout << s1.capacity() << endl;
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1.operator[](i) << " ";
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		s1[i] += 1;
//	}
//	cout <<s1<<endl;
//	//operator[]��at������
//	//operator[]ʹ�ö���
//	//atʹ�õ������쳣
//	try
//	{
//		s1.at(100);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

int main()
{
	string s1;
	s1.push_back('a');
	s1.append("bcde");
	cout << s1<<endl;
	s1 += " ";
	s1 += "hello world";
	cout << s1 << endl;

	return 0;
}