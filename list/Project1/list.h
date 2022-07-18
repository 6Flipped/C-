#pragma once
#include<assert.h>
namespace lwz
{
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;

		list_node(const T& val=T())
			:_next(nullptr)
			,_prev(nullptr)
			,_data(val)
		{}
	};

	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T,Ref,Ptr> self;	
		Node* _node;
		__list_iterator(Node* node)
			:_node(node)
		{}

		//析构函数 ---节点不属于迭代器，不需要迭代器释放
		//拷贝构造和复制重载 ---默认生成的浅拷贝就可以

		Ref operator*()
		{
			return _node->_data;
		}

		self operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self& operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const self& it)
		{
			return _node != it._node;
		}

		bool operator==(const self& it)
		{
			return _node == it._node;
		}
	};


	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T,const T&,const T*> const_iterator;

		iterator begin()
		{
			//return iterator(_head->_next);
			//单参数的构造函数支持隐式类型转化
			return _head->_next;
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			//return iterator(_head->_next);
			//单参数的构造函数支持隐式类型转化
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		//拷贝构造lt2(lt1)
		/*list(const list<T>& lt)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			for (auto e : lt)
			{
				push_back(e);
			}
		}*/

		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}

		//拷贝构造现代写法
		list(const list<T>& lt)
		{
			empty_init();
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
				it++;
			}
		}

		void push_back(const T& x)
		{
			/*Node* tail = _head->_prev;
			Node* newnode = new Node(x);

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		//插入在pos位置之前
		iterator insert(iterator pos, const T& x)
		{
			Node* newNode = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			//prev newnode cur
			prev->_next = newNode;
			newNode->_next = cur;
			newNode->_prev = prev;
			cur->_prev = newNode;
			return iterator(newNode);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur= pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			//prev next
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			return iterator(next);
		}


		private:
			Node* _head;

	};

	void print_list(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test1_list()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		print_list(lt);
	}

	struct AA
	{
		AA(int a1=0,int a2=0)
			:_a1(a1)
			,_a2(a2)
		{}
		int _a1;
		int _a2;
	};

	void test2_list()
	{
		list<AA> lt;
		lt.push_back(AA(1, 1));
		lt.push_back(AA(2, 2));
		lt.push_back(AA(3, 3));
		lt.push_back(AA(4, 4));

		list<AA>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._a1 << "-"<< (*it)._a2<<" ";
			cout << it->_a1 << "-" << it->_a2 << " ";
			++it;
		}
		cout << endl;
	}

	void test3_list()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		print_list(lt);

		lt.push_front(1);
		lt.push_front(2);
		lt.push_front(3);
		lt.push_front(4);
		print_list(lt);

		lt.pop_back();
		lt.pop_back();
		print_list(lt);

		lt.pop_front();
		lt.pop_front();
		print_list(lt);

	}

	void test4_list()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);
		print_list(lt);

		list<int>::iterator it1 = lt.begin();
		while (it1 != lt.end())
		{
			if (*it1 % 2 == 0)
			{
				lt.insert(it1, *it1 * 10);
			}
			it1++;
		}
		print_list(lt);

	}

	void test5_list()
	{
		list<int> lt;
		lt.push_back(2);
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);
		lt.push_back(6);
		print_list(lt);

		//删除所有偶数
		list<int>::iterator it1 = lt.begin();
		while (it1 != lt.end())
		{
			if (*it1 % 2 == 0)
			{
				it1=lt.erase(it1);
			}
			else
				it1++;
		}
		print_list(lt);

		lt.clear();
		print_list(lt);

		lt.push_back(2);
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);
		lt.push_back(6);
		print_list(lt);

	}

	void test6_list()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);
		print_list(lt);

		list<int> lt1(lt);
		print_list(lt1);
		list<int> lt2 = lt1;
		print_list(lt2);


	}

}