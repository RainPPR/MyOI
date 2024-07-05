#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e6 + 10;
int p[N], cnt;
bool st[N];
void primes(int n)
{
	for (int i = 2 ; i <= n ; ++i)
	{
		if (!st[i])
		{
			p[cnt++] = i;
			for (int j = i + i ; j <= n ; j += i)
				st[j] = true;
		}
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	primes(n);
	printf("%d", cnt);
	return 0;
}
