#pragma once
#include<assert.h>
namespace lwz
{
	class string
	{
		typedef char* iterator;
		typedef const char* const_iterator;

	public:
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strncpy(tmp, _str, _size + 1);
				delete[] _str;

				_str = tmp;
				_capacity = n;
			}
		}

		string& operator += (char ch)
		{
			push_back(ch);
			return *this;
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			_size++;
		}

		void append(const char* str)
		{
			size_t len = _size + strlen(str);
			if (len > _capacity)
			{
				reserve(len);
			}
			strcpy(_str + _size, str);
			_size = len;
		}
		string& operator += (const char* str)
		{
			append(str);
			return *this;
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 0 : 2 * _capacity);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}
		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);
			const char* ret = strstr(_str + pos, str);
			if (ret)
			{
				return ret - _str;
			}
			else
				return pos;
		}

		istream& operator>>(istream& in, string& s)
		{
			s.clear();
			char ch;
			ch = in.get();
			while (ch != ' ' && ch != '\n')
			{
				s += ch;
				ch = in.get();
			}
			return in;
		}
		istream& getline(istream& in, string& s)
		{
			s.clear();
			char ch;
			ch = in.get();
			while (ch != '\n')
			{
				s += ch;
				ch = in.get();
			}
			return in;
		}


		ostream& operator<<(ostream& out, const string& s)
		{
			for (auto e : s)
			{
				out << e;
			}
			return out;
		}


		bool operator<(const string& s1, const string& s2)
		{
			return strcmp(s1.c_str(), s2.c_str()) < 0;
		}
		bool operator==(const string& s1, const string& s2)
		{
			return strcmp(s1.c_str(), s2.c_str()) == 0;
		}
		bool operator<=(const string& s1, const string& s2)
		{
			return s1 < s2 || s1 == s2;
		}
		bool operator>(const string& s1, const string& s2)
		{
			return !(s1 <= s2);
		}
		bool operator>=(const string& s1, const string& s2)
		{
			return !(s1 < s2);
		}
		bool operator!=(const string& s1, const string& s2)
		{
			return !(s1 == s2);
		}

		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}


		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			size_t leftLen = _size - pos;
			if (len >= leftLen)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}

		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		string& operator=(const string& s)
		{
			if (this != &s)//防止自己给自己赋值
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}

		void swap(string& s)
		{
			//域作用限定符，优先在类域里面
			//直接交换，减少了多次拷贝构造
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}

		string& operator=(string s)
		{
			swap(s);
			return *this;
		}

		const char& operator[](size_t i) const
		{
			assert(i < _size);
			return _str[i];
		}

		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}

	private:
		char* _str;
		size_t _size;		
		size_t _capacity;
	};
}
