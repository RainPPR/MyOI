#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
using namespace std;
bool prime[32769] = {false};
void getprime(int &m)
{
	int mmax = -1;
	prime[0] = false;
	prime[1] = false;
	for (int i = 2 ; i <= m ; i++)
	{
		if (prime[i] == false)
		{
			for (int j = i << 1 ; j <= m ; j += i)
			{
				prime[j] = true;
			}
			mmax = max(mmax, i);
		}
		prime[i] = !prime[i];
	}
	m = mmax;
	return;
}
bool isw(int nt)
{
	int n1 = nt;
	int n2 = 0;
	while (nt)
	{
		n2 = n2 * 10 + nt % 10;
		nt /= 10;
	}
	return n1 == n2;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	getprime(b);
	for (int i = a ; i <= b ; i++)
	{
		if (prime[i] && isw(i))
		{
			printf("%d ", i);
		}
	}
	return 0;
}
