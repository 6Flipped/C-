#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;

void test_set1()
{
	set<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(3);
	s.insert(1);
	s.insert(1);
	s.insert(4);
	s.insert(4);
	//����+ȥ��
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//const����������ͨ��������ʵ��ͬһ�������������޸�
		//ԭ�����ڵײ㶼��ʹ��const_iteratorʵ��
		//*it=10
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//֧�ֵ���������֧�ַ�Χfor
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_set2()
{
	set<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(3);
	s.insert(1);
	s.insert(1);
	s.insert(4);
	s.insert(4);
	//set�е��㷨
	//O(logN)
	set<int>::iterator pos = s.find(2);
	
	if (pos != s.end())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	//�㷨�е�find
	//O(N)
	//һ������vector
	pos = find(s.begin(), s.end(), 2);
	if (pos != s.end())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}


void test_set3()
{
	set<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(3);
	s.insert(1);
	s.insert(1);
	s.insert(4);
	s.insert(4);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	//�ھ�ɾ�����ھͲ���
	//ɾ���ɹ�����1��û�з���0
	s.erase(3);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	/*int x;
	while (cin >> x)
	{
		set<int>::iterator pos = s.find(x);
		if (pos != s.end())
		{
			s.erase(pos);
			cout << "�ɹ�" << endl;
			for (auto e : s)
			{
				cout << e << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "null" << endl;
			for (auto e : s)
			{
				cout << e << " ";
			}
			cout << endl;
		}
	}*/

	if (s.count(5))
	{
		cout << "OK" << endl;
	}
}

void test_set4()
{
	set<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(3);
	s.insert(9);
	s.insert(1);
	s.insert(4);
	s.insert(6);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	
	//���ش��ڵ���val��λ��
	set<int>::iterator lowIt = s.lower_bound(3);
	lowIt = s.lower_bound(0);
	cout << *lowIt << endl;
}


void test_set5()
{
	multiset<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(3);
	s.insert(9);
	s.insert(9);
	s.insert(9);
	s.insert(1);
	s.insert(1);
	s.insert(1);
	s.insert(4);
	s.insert(4);
	s.insert(4);
	s.insert(6);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

}


void test_map1()
{
	map<string, string> dict;

	//pair���캯��
	dict.insert(pair<string, string>("sort", "����"));
	pair<string, string> kv("insert", "����");
	dict.insert(kv);

	//make_pair
	dict.insert(make_pair("left", "���"));

	//C++11
	//dict.insert({ "right", "�ұ�" });

	//����
	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		//cout << *it << " ";//it->operator*()
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first <<":"<< it->second << endl;
		
		++it;
	}
	cout << endl;

	for (auto kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;

	}
	cout << endl;

}

void test_map2()
{
	string arr[] = { "ƻ��","����" ,"ƻ��","����" ,"ƻ��","����" ,"�㽶","ƻ��","����" ,"�㽶" };
	map<string, int> countMap;
	for (auto& str : arr)
	{
		map<string, int>::iterator it = countMap.find(str);
		if (it != countMap.end())
		{
			it->second++;
		}
		else
		{
			countMap.insert(make_pair(str, 1));
		}
	
	}
	for (auto kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;

	}
	cout << endl;


}

void test_map3()
{
	//���map��multimap��֧��operator[]
	multimap<string, string> dict;
	dict.insert(make_pair("left", "���"));
	dict.insert(make_pair("left", "ʣ��"));
	dict.insert(make_pair("left", "���"));

	for (auto kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;

	}
	cout << endl;
}

int main()
{
	//test_set1();
	//test_set2();
	//test_set3();
	//test_set4();
	//test_set5();
	//test_map1();
	//test_map1();
	test_map3();
	return 0;
}