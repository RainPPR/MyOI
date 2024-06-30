#include<cstdio>
#include<iostream>

using namespace std;

const int N = 1e5 + 10, M = 31 * N;

int n, idx;
int a[N];
int son[M][2];

void insert(int x)
{
	int p = 0;
	for (int i = 30 ; i >= 0 ; --i)
	{
		int u = x >> i & 1;
		if (!son[p][u])
			son[p][u] = ++idx;
		p = son[p][u];
	}
}

int query(int x)
{
	int p = 0, res = 0;
	for (int i = 30 ; i >= 0 ; --i)
	{
		int u = x >> i & 1;
		if (son[p][!u])
			p = son[p][!u], res = (res << 1) + !u;
		else
			p = son[p][u], res = (res << 1) + u;
	}
	return res;
}

int main()
{
	scanf("%d", &n);

	int res = 0;
	for (int i = 0 ; i < n ; ++i)
	{
		scanf("%d", a + i);
		insert(a[i]);	// 先插入再查询，减少判断
		int t = query(a[i]);
		res = max(res, a[i] ^ t);
	}

	printf("%d\n", res);
	return 0;
}
