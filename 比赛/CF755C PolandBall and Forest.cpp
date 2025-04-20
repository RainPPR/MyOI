#include<cstdio>
#include<iostream>

using namespace std;

const int N = 1e4 + 10;

int n, m;
int p[N];

int find(int x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d", &n);

	for (int i = 1 ; i <= n ; ++i)
		p[i] = i;

	int ans = n, x;
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", &x);

		int fa = find(i), fb = find(x);
		if (fa != fb)
			--ans, p[fa] = fb;
	}

	printf("%d", ans);
	return 0;
}

