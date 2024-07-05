#include<iostream>
#include<cstdio>
using namespace std;
int n, a;
void getans(int x)
{
	for (int i = 2 ; i <= x / i ; ++i)
	{
		if (x % i == 0)
		{
			int k = 0;
			while (x % i == 0)
			{
				x /= i;
				++k;
			}
			printf("%d %d\n", i, k);
		}
	}
	if (x > 1)
	{
		printf("%d 1\n", x);
	}
	printf("\n");
}
int main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &a);
		getans(a);
	}
	return 0;
}
