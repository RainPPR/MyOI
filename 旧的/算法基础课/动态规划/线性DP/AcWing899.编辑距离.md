# AcWing 899. 编辑距离
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1010;
const int S = 15;
char a[N][S];
char q[S];
int n, m, d;
int f[S][S];
inline int MIN(int a, int b)
{
	return (a < b) ? a : b;
}
inline int MAX(int a, int b)
{
	return (a > b) ? a : b;
}
inline int emin(char *a, char *b, int n, int m)
{
	for (int i = 0 ; i <= m ; ++i)
		f[0][i] = i;
	for (int i = 0 ; i <= n ; ++i)
		f[i][0] = i;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j)
		{
			f[i][j] = MIN(f[i - 1][j], f[i][j - 1]) + 1;
			if (a[i] == b[j])
				f[i][j] = MIN(f[i][j], f[i - 1][j - 1]);
			else
				f[i][j] = MIN(f[i][j], f[i - 1][j - 1] + 1);
		}
	return f[n][m];
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0 ; i < n ; ++i)
		scanf("%s", a[i] + 1);
	while (m--)
	{
		scanf("%s %d", q + 1, &d);
		int cnt = 0;
		for (int i = 0 ; i < n ; ++i)
			if (emin(a[i], q, strlen(a[i] + 1), strlen(q + 1)) <= d)
				++cnt;
		printf("%d\n", cnt);
	}
	return 0;
}
```