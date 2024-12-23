#include<cstdio>
#include<iostream>
using namespace std;
const int N = 310;
int n;
int s[N];
int f[N][N];
int main()
{
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d", s + i);
	for (int i = 1 ; i <= n ; ++i)
		s[i] += s[i - 1];
	for (int len = 2 ; len <= n ; ++len)			// 枚举区间长度
		for (int i = 1 ; i + len - 1 <= n ; ++i)	// 枚举区间开头
		{
			int l = i, r = i + len - 1;				// 区间两端点
			f[l][r] = 2e9;
			for (int k = l ; k < r ; ++k)			// 枚举划分位置
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
		}
	printf("%d\n", f[1][n]);
	return 0;
}
