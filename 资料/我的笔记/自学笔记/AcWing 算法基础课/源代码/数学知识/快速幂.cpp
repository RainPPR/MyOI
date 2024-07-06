#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int mod = 1e9;
// a ^ k mod p
ll quick_pow(int a, int k, int p)
{
	ll res = 1;
	while (k)	// ������k�Ķ����Ʊ�ʾ
	{
		if (k & 1)	// k_2 ����һλ��1
			res = (ll)res * a % p;
		k >>= 1;
		a = (ll)a * a % p;
	}
	return res;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	while (n--)
	{
		int a, k, p;
		scanf("%d %d %d", &a, &k, &p);
		printf("%d\n", quick_pow(a, k, p));
	}
	return 0;
}
