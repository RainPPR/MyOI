#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<string.h>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
void get(string &sl, string &sr)
{
	string str;
	getline(cin, str);
	for (int i = 0 ; i < str.size() ; i++)
	{
		if (str[i] == '=')
		{
			for (int j = i + 1 ; j < str.size() ; j++)
			{
				if (str[j] != ' ' && str[j] != '\n' && str[j] != '\r')
				{
					sr = sr + str[j];
				}
			}
			return;
		}
		else if (str[i] != ' ' && str[i] != '\n' && str[i] != '\r')
		{
			sl = sl + str[i];
		}
	}
	return;
}
int _stod(string str)
{
	int n = 0;
	int i = 0;
	bool fu = false;
	if (str[0] == '-')
	{
		i = 1;
		fu = true;
	}
	else if (str[0] == '+')
	{
		i = 1;
	}
	for (; i < str.size() ; i++)
	{
		n = n * 10 + str[i] - '0';
	}
	if (fu)
	{
		n = -n;
	}
	return n;
}
string _dtos(int m)
{
	bool fu = false;
	if (m < 0)
	{
		fu = true;
		m = -m;
	}
	string str;
	while (m)
	{
		str = str + char (m % 10 + '0');
		m /= 10;
	}
	if (fu)
	{
		str = "-" + str;
	}
	return str;
}
char getfu(string str)
{
	for (int i = 0 ; i < str.size() ; i++)
	{
		if (((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') && (str[i] <= 'Z')))
		{
			return str[i];
		}
	}
	return 0;
}
char getfu(string str1, string str2)
{
	char a = getfu(str1);
	if (a == 0)
	{
		return getfu(str2);
	}
	else
	{
		return a;
	}
}
void cl(string &str, char fu)
{
	string q;
	if (str[0] == fu)
	{
		q = "1";
	}
	for (int i = 0 ; i < str.size() - 1 ; i++)
	{
		q += str[i];
		if (((str[i] == '-') || (str[i] == '+')) && (str[i + 1] == fu))
		{
			q += '1';
		}
	}
	q += str[str.size() - 1];
	str = q;
}
void getstr(string str, char x, int &xi, int &chang)
{
	cl(str, x);
	xi = 0;
	chang = 0;
	string duan[1000];
	int c = 0;
	bool n = true;
	for (int i = 0 ; i < str.size() ; i++)
	{
		if (str[i] == '+')
		{
			if (n)
			{
				chang += _stod(duan[c]);
				duan[c] = "";
				c--;
			}
			else
			{
				duan[c].pop_back();
				xi += _stod(duan[c]);
				duan[c] = "";
				c--;
			}
			c++;
			n = true;
		}
		else if (str[i] == '-')
		{
			if (n)
			{
				chang += _stod(duan[c]);
				duan[c] = "";
				c--;
			}
			else
			{
				duan[c].pop_back();
				xi += _stod(duan[c]);
				duan[c] = "";
				c--;
			}
			duan[++c] = "-";
			n = true;
		}
		else
		{
			duan[c] += str[i];
			if (str[i] == x)
			{
				n = false;
			}
		}
	}
	if (n)
	{
		chang += _stod(duan[c]);
		duan[c] = "";
		c--;
	}
	else
	{
		duan[c].pop_back();
		xi += _stod(duan[c]);
		duan[c] = "";
		c--;
	}
}
int main()
{
	string sl;
	string sr;
	get(sl, sr);
	char x = getfu(sl, sr);
	if (x == 0)
	{
		return 0;
	}
	int l_chang = 0, l_xi = 0;
	getstr(sl, x, l_xi, l_chang);
	int r_chang = 0, r_xi = 0;
	getstr(sr, x, r_xi, r_chang);
	//printf("方程左面 / 式子: %s\n", sl.c_str());
	//printf("         | 字母系数: %d(%c)\n", l_xi, x);
	//printf("         \\ 常数项和: %d\n", l_chang);
	//printf("方程右面 / 式子: %s\n", sr.c_str());
	//printf("         | 字母系数: %d(%c)\n", r_xi, x);
	//printf("         \\ 常数项和: %d\n", r_chang);
	//printf("结合方程: (%d%c) + (%d) = (%d%c) + (%d)\n", l_xi, x, l_chang, r_xi, x, r_chang);
	r_chang -= l_chang;
	l_xi -= r_xi;
	//printf("转化方程: %d%c = %d\n", l_xi, x, r_chang);
	float ov = (float) r_chang / l_xi;
	if (ov == -0.0)
	{
		ov = 0.0;
	}
	//printf("系数化一: %c = %f\n", x,/*r_chang/l_xi*/ov);
	//printf("格式化  : %c = %.3f\n", x,/*r_chang/l_xi*/ov);
	//printf("输出: %c=%.3f\n", x, ov);
	printf("%c=%.3f", x, ov);
	return 0;
}
