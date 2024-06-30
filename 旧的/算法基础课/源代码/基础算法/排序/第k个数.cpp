#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1e6 + 1;
int a[MAXN];
int n;
void Swap(int &a, int &b)
{
	a ^= b, b ^= a, a ^= b;
}
int quick_sort(int l, int r, int k)
{
	if (l == r)
	{
		return a[l];
	}
	int x = a[l];
	int i = l - 1, j = r + 1;
	while (1)
	{
		while (a[++i] < x);
		while (a[--j] > x);
		if (i < j)
			Swap(a[i], a[j]);
		else
			break;
	}
	int len = j - l + 1;
	if (k <= len)
	{
		return quick_sort(l, j, k);
	}
	else
	{
		return quick_sort(j + 1, r, k - len);
	}
}
int main()
{
	int k = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0 ; i < n ; ++i)
		scanf("%d", a + i);
	printf("%d\n", quick_sort(0, n - 1, k));
	return 0;
}
