#include<iostream>
#include<cstdio>
using namespace std;
int lobit(int x)
{
	return x & -x;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	while (n--)
	{
		int x = 0;
		cin >> x;
		int res = 0;
		while (x)
		{
			x -= lobit(x);
			res++;
		}
		printf("%d\n", res);
	}
	return 0;
}
