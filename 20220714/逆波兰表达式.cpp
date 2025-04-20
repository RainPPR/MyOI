#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
using namespace std;
struct mydc
{
	bool is = 0;	//0-·ûºÅ 1-Êý×Ö
	char c = 0;
	double n = 0.0;
};
double suan(double a, char op, double b)
{
	switch (op)
	{
		case '+':
			return a + b;
			break;
		case '-':
			return a - b;
			break;
		case '*':
			return a * b;
			break;
		case '/':
			return a / b;
			break;
	}
	return 0;
}
int main()
{
	stack<mydc>st;
	bool over = false;
	while (!over)
	{
		string str;
		while (1)
		{
			char c;
			c = getchar();
			if (c == ' ')
			{
				break;
			}
			else if (c == '\n' || c == '\r')
			{
				over = true;
				break;
			}
			else
			{
				str += c;
			}
		}
		if (str == "+" || str == "-" || str == "*" || str == "/")
		{
			mydc temp;
			temp.c = str[0];
			st.push(temp);
		}
		else
		{
			double num = atof(str.c_str());
			mydc temp = {1, 0, num};
			st.push(temp);
		}
		if (st.size() >= 3)
		{
			mydc topt = st.top();
			st.pop();
			if (st.top().is == 1 && topt.is == 1)
			{
				double a = topt.n;
				double b = st.top().n;
				st.pop();
				char op = st.top().c;
				st.pop();
				double res = suan(a, op, b);
				mydc temp = {1, 0, res};
				st.push(temp);
			}
			else
			{
				st.push(topt);
			}
		}
	}
	while (st.size() > 1)
	{
		mydc topt = st.top();
		st.pop();
		double a = topt.n;
		double b = st.top().n;
		st.pop();
		char op = st.top().c;
		st.pop();
		double res = suan(a, op, b);
		mydc temp = {1, 0, res};
		st.push(temp);
	}
	printf("%f\n", st.top().n);
	return 0;
}
