#include <iostream>
using namespace std;

class String
{
private:
	char* _pstr;
public:
	//��ֵ�����������
	String& operator =(const String& s)//����һ:��ͳд������ɾ���󿪱ٿռ丳ֵ
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

	String& operator =(const String& s)//������:��ͳд�����ȿ��ٿռ丳ֵ����ɾ�����������ţ���Ϊ����ɾ��ԭ�е�_pstr��ֵ�Ժ󣬲��ܿ��ٳ����ռ�
	{
		if (this != &s)
		{
			String tmp(s);

			delete[]_pstr;
			swap(_pstr, tmp._pstr);
		}

		return *this;
	}

	String& operator =(String s)//������:�ִ�д��--->�ı䴫ֵ��ʽ�����ÿ������췽����Ȼ��ֱ�ӽ�������
	{
		swap(_pstr, s._pstr);

		return *this;
	}

};


