#include<iostream>
#include<stack>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;

#include"stack.h"
#include"Queue.h"

namespace std
{
	void test_stack()
	{
		stack<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);

		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}

	void test_queue()
	{
		queue<int>q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}

	void test_priority_queue()
	{
		priority_queue<int,vector<int>,greater<int>> pq;
		pq.push(6);
		pq.push(4);
		pq.push(2);
		pq.push(1);
		pq.push(5);
		pq.push(3);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}

int main()
{
	//std::test_stack();
	//std::test_queue();
	//std::test_priority_queue();
	lwz::test_stack();
	lwz::test_queue();
	lwz::test_priority_queue();
	return 0;
} 