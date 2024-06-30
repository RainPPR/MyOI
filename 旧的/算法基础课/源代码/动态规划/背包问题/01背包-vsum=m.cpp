#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF = -2147483648;
const int N = 1010;
int n,	// 物品数
    m;	// 背包总容量
int v[N],	// 物品的体积
    w[N];	// 物品的价值
int f[N];
int main()
{
	cin >> n >> m;
	f[0] = 0;
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d %d", v + i, w + i), f[i] = INF;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = m ; j >= v[i]; --j)
		{
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	cout << f[m] << endl;
	return 0;
}
