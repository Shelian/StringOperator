#include <iostream>
using namespace std;

class String
{
private:
	char* _pstr;
public:
	//赋值运算符的重载
	String& operator =(const String& s)//方法一:传统写法，先删除后开辟空间赋值
	{
		if (this != &s)
		{
			delete[]_pstr;
			_pstr = NULL;

			_pstr = new char[strlen(s._pstr) + 1];
			strcpy(_pstr, s._pstr);
		}

		return *this;
	}

	String& operator =(const String& s)//方法二:传统写法，先开辟空间赋值，后删除，方法更优，因为可能删除原有的_pstr的值以后，不能开辟出来空间
	{
		if (this != &s)
		{
			String tmp(s);

			delete[]_pstr;
			swap(_pstr, tmp._pstr);
		}

		return *this;
	}

	String& operator =(String s)//方法三:现代写法--->改变传值方式，调用拷贝构造方法，然后直接交换即可
	{
		swap(_pstr, s._pstr);

		return *this;
	}

};


