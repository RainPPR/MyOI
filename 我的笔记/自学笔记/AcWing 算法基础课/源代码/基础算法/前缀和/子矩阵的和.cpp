#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1010;
int n, m, q;
int a[N][N], s[N][N];
int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j)
		{
			scanf("%d", a[i] + j);
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	while (q--)
	{
		int x1 = 0, y1 = 0;
		int x2 = 0, y2 = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
	}
	return 0;
}
