#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 510, INF = 1e9;
int n;
int a[N][N];
int f[N][N];
int main()
{
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= i ; ++j)
			scanf("%d", a[i] + j);
	for (int i = 0 ; i <= n ; ++i)
		for (int j = 0 ; j <= i ; ++j)
			f[i][j] = -INF;
	for (int i = 1 ; i <= n ; ++i)
		f[n][i] = a[n][i];
	for (int i = n - 1 ; i >= 1 ; --i)
		for (int j = 1 ; j <= i ; ++j)
			f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
	printf("%d\n", f[1][1]);
	return 0;
}
