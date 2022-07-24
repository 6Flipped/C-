#pragma once
#include<assert.h>
namespace lwz
{
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}
		const T& front()
		{
			return _con.front();
		}

		const T& back()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;

	};

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


	//仿函数/函数对象---->对象可以像函数一样去使用
	template<class T>
	struct less
	{
		bool operator()(const T& x, const T& y) const
		{
			return x < y;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& x, const T& y) const
		{
			return x > y;
		}
	};
	//优先级队列---大堆用小于，小堆用大于
	template<class T,class Container=vector<T>,class Compare=less<T>>
	class priority_queue
	{
	public:
		void AdJustUp(int child)
		{
			Compare comFunc;
			size_t parent = (child-1) / 2;
			while (child > 0)
			{
				if (comFunc(_con[parent] , _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}
		}

		void AdJustDown(int parent)
		{
			Compare comFunc;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && comFunc(_con[child], _con[child+1]))
				{
					++child;
				}
				if (comFunc(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					break;
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			AdJustUp(_con.size()-1);
		}

		void pop()
		{
			assert(!_con.empty());
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdJustDown(0);
		}

		const T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};

	

	void test_priority_queue()
	{
		//priority_queue<int, vector<int>> pq;
		priority_queue<int, vector<int>,greater<int>> pq;
		pq.push(2);
		pq.push(5);
		pq.push(1);
		pq.push(6);
		pq.push(8);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}


	void test_Functional()
	{
		vector<int> v;
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(1);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		sort(v.begin(), v.end(),greater<int>());
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}