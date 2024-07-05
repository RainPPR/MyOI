#include<cstdio>
#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
int main()
{
	int d = 0;
	scanf("%d", &d);
	while (d--)
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
	return 0;
}
