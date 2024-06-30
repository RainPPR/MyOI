#include<iostream>
#include<cstdio>
using namespace std;
const int N = 100010;
int q[N], hh, tt = -1;
void push(int x)
{
	q[++tt] = x;
}
void pop()
{
	++hh;
}
bool empty()
{
	return hh > tt;
}
int front()
{
	return q[hh];
}
int main()
{
	int m = 0;
	scanf("%d", &m);
	while (m--)
	{
		string op;
		cin >> op;
		if (op == "push")
		{
			int x = 0;
			scanf("%d", &x);
			push(x);
		}
		else if (op == "pop")
			pop();
		else if (op == "empty")
			if (empty())
				printf("YES\n");
			else
				printf("NO\n");
		else
			printf("%d\n", front());
	}
	return 0;
}
