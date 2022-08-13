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
	//排序+去重
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//const迭代器和普通迭代器其实是同一个，都不允许修改
		//原因在于底层都是使用const_iterator实现
		//*it=10
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//支持迭代器即可支持范围for
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
	//set中的算法
	//O(logN)
	set<int>::iterator pos = s.find(2);
	
	if (pos != s.end())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	//算法中的find
	//O(N)
	//一般用于vector
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
	//在就删，不在就不动
	//删除成功返回1，没有返回0
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
			cout << "成功" << endl;
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
	
	//返回大于等于val的位置
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

	//pair构造函数
	dict.insert(pair<string, string>("sort", "排序"));
	pair<string, string> kv("insert", "插入");
	dict.insert(kv);

	//make_pair
	dict.insert(make_pair("left", "左边"));

	//C++11
	//dict.insert({ "right", "右边" });

	//遍历
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
	string arr[] = { "苹果","西瓜" ,"苹果","西瓜" ,"苹果","西瓜" ,"香蕉","苹果","西瓜" ,"香蕉" };
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
	//相比map，multimap不支持operator[]
	multimap<string, string> dict;
	dict.insert(make_pair("left", "左边"));
	dict.insert(make_pair("left", "剩余"));
	dict.insert(make_pair("left", "左边"));

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