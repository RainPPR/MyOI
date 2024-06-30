#include<iostream>
#include<cstdio>
using namespace std;
const int N = 100010;
int stk[N], tt;
void push(int x)
{
	stk[++tt] = x;
}
void pop()
{
	--tt;
}
bool empty()
{
	return tt == 0;
}
int top()
{
	return stk[tt];
}
int main()
{
	int m = 0;
	scanf("%d",&m);
	while(m--)
	{
		string op;
		cin >> op;
		if(op == "push")
		{
			int x = 0;
			scanf("%d",&x);
			push(x);
		}
		else if(op == "pop")
			pop();
		else if(op == "empty")
			if(empty())
				printf("YES\n");
			else
				printf("NO\n");
		else
			printf("%d\n",top());
	}
	return 0;
}
