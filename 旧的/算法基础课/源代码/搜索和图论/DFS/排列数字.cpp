#include<iostream>
#include<cstdio>
using namespace std;
const int N = 10;
int n;
int a[N];
bool st[N];
void dfs(int now)
{
	if (now == n)
	{
		for (int i = 0 ; i < n ; i++)
			printf("%d ", a[i]);
		printf("\n");
		return;
	}
	for (int i = 1 ; i <= n ; i++)
		if (!st[i])
		{
			st[i] = 1;
			a[now] = i;
			dfs(now + 1);
			st[i] = 0;
		}
}
int main()
{
	scanf("%d", &n);
	dfs(0);
	return 0;
}
