// File: 一个简单的整数问题.cpp

#include <cstdio>
#include <cstring>
#define lowbit(x) ((x) & -(x))

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N];			// 原数组
long long tr[N];	// 查分数组

void add(int x, int c)
{
	for (int i = x ; i <= n ; i += lowbit(i))
		tr[i] += c;
}

long long sum(int x)
{
	long long res = 0;
	for (int i = x ; i ; i -= lowbit(i))
		res += tr[i];
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", a + i);
		add(i, a[i] - a[i - 1]);
	}

	char op[2];
	int l, r, d;
	while (m--)
	{
		scanf("%s %d", op, &l);
		if (op[0] == 'C')
		{
			scanf("%d %d", &r, &d);
			add(l, d);
			add(r + 1, -d);
		}
		else
		{
			printf("%lld\n", sum(l));
		}
	}
	return 0;
}
