#pragma once
#include<assert.h>
namespace lwz
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{};
	
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstoage, v._endofstoage);
		}
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			this->swap(tmp);
		}


		vector<T>& operator=(vector<T> v)
		{
			this->swap(v);
			return *this;
		}

		vector(size_t n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstoage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		//资源管理
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstoage;
			}
		}


		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstoage - _start;
		}

		void reserve(size_t n)
		{
			size_t sz = size();
			if (n > capacity())
			{
				T* tmp = new T[n];
				//memcpy(tmp, _start, size() * sizeof(T));
				for (size_t i = 0; i < size(); i++)
					tmp[i] = _start[i];
				delete[] _start;
				_start = tmp;
			}
			_finish = _start + sz;
			_endofstoage = _start + n;
		}

		void resize(size_t n,const T& val=T())
		{
			if (n > capacity())
			{
				reserve(n);
			}
			if (n > size())
			{
				while (_finish < _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
			else
			{
				_finish = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstoage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}
		
		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		void pop_back()
		{
			if (_finish > _start)
			{
				_finish--;
			}
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			//空间够不够
			if (_finish == _endofstoage)
			{
				//扩容后导致_start更新，但是pos还是指向原来的空间
				//原来空间在扩容后被释放掉，导致迭代器失效
				//需要更新一下pos
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + n;
			}

			//挪动数据
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}

			*pos = x;
			_finish++;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			_finish--;
			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstoage;
	};

	void test1_vector()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		v.pop_back();
		v.pop_back();
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test2_vector()
	{
		/*vector<int> v;
		v.resize(10, -1);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;*/

		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		//v.push_back(5);

		v.insert(v.begin(), 0);
		v.insert(v.begin(), 0);
		v.insert(v.begin(), 0);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	void test4_vector()
	{
		vector<int> v;
		v.push_back(10);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it=v.erase(it);
			}
			else
				it++;
		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	void test5_vector()
	{
		vector<int> v(10,2);
		std::string s("hello");
		vector<int> v1(v);
		vector<char> v2(s.begin(), s.end());
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}