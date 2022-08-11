#include<iostream>
#include<vector>
using namespace std;
#include"vector.h"


int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	v.insert(v.begin(),v.begin()+3,v.begin()+6);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	/*vector<int> v(5,1);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v1(v.begin(), v.end()-1);

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;*/

	/*vector<int> v2(5);
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout <<endl<<v2.size() << endl;*/
	//lwz::test1_vector();
	//lwz::test2_vector();
	//lwz::test3_vector();
	//lwz::test4_vector();
	//lwz::test5_vector();
	return 0;
}