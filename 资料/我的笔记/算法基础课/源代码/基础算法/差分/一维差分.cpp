#include<iostream>
#include<cstdio>
using namespace std;
const int N = 100010;
int n, m;
int a[N], b[N];
void add(int l, int r, int c)
{
	b[l] += c;
	b[r + 1] -= c;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", a + i);
		add(i, i, a[i]);
	}
	while (m--)
	{
		int l = 0, r = 0, c = 0;
		scanf("%d %d %d", &l, &r, &c);
		add(l, r, c);
	}
	for (int i = 1 ; i <= n ; ++i)
	{
		b[i] += b[i - 1];
		printf("%d ", b[i]);
	}
	return 0;
}
