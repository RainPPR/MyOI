#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 110;

int n,	// 物品数
    m;	// 背包总容量
int v[N][N],	// 每组中，物品的体积
    w[N][N],	// 每组中，物品的价值
    s[N];	// 每组的物品个数
int f[N];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", s + i);
		for (int j = 0 ; j < s[i] ; ++j)
			scanf("%d %d", v[i] + j, w[i] + j);
	}
	for (int i = 1 ; i <= n ; ++i)
		for (int j = m ; j >= 0 ; --j)
			for (int k = 0 ; k < s[i] ; ++k)
				if (v[i][k] <= j)
					f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
	printf("%d", f[m]);
	return 0;
}
