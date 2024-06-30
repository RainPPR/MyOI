#include<iostream>
#include<cstdio>
using namespace std;
int n, x;
bool is_prime(int x)
{
	if (x < 2) return false;
	for (int i = 2 ; i <= x / i ; ++i)
		if (x % i == 0)
			return false;
	return true;
}
int main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &x);
		if (is_prime(x))
			printf("Yes\n");
		else
			printf("No\n");
	}
}
