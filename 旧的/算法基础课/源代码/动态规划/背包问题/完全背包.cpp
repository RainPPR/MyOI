#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;

int n,	// 物品数
    m;	// 背包总容量
int v[N],	// 物品的体积
    w[N];	// 物品的价值
int f[N];
int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1 ; i <= n ; ++i)
		scanf("%d %d", v + i, w + i);

	for (int i = 1 ; i <= n ; ++i)
		for (int j = v[i] ; j <= m ; ++j)
			f[j] = max(f[j], f[j - v[i]] + w[i]);

	printf("%d", f[m]);

	return 0;
}
