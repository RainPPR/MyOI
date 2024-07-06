# MRAVOJED
不同情况，分类讨论
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 110;
char a[N][N];
int n, m;
int ax = -1, ay = -1, as = 0;
int bx = -1, by = -1, bs = 0;
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= n ; i++)
	{
		scanf("%s", a[i] + 1);
		if ((ax == -1) && (ay == -1))
			for (int j = 1 ; j <= m ; j++)
				if (a[i][j] == 'x')
					ax = i, ay = j, as++;
	}
	ay = ay - as + 1;
	int d = ax;
	while ((d <= n) && (a[d][ay] == 'x'))
		d++;
	as = min(as, d - ax);
	printf("%d %d %d\n", ax, ay, as);
	for (int i = 0 ; i < as ; i++)
		for (int j = 0 ; j < as ; j++)
			a[ax + i][ay + j] = '.';
	for (int i = n ; i >= 1 ; i--)
		if ((bx == -1) && (by == -1))
			for (int j = 1 ; j <= m ; j++)
				if (a[i][j] == 'x')
					bx = i, by = j, bs++;
	if ((bx == -1) && (by == -1))
		printf("%d %d 1\n", ax, ay);
	else
	{
		by = by - bs + 1;
		d = bx;
		while ((d >= 1) && (a[d][by] == 'x'))
			d--;
		bs = max(bs, bx - d);
		printf("%d %d %d\n", bx - bs + 1, by, bs);
	}
	return 0;
}
```