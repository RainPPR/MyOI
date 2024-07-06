#include<cstdio>
#include<iostream>

using namespace std;

const int N = 5e4 + 10;

int n, m;
int p[N],	// father
    d[N];	// distance

// 返回 x 所在集合的编号（祖宗结点）
int find(int x)
{
	if (p[x] != x)	// x 不是树根
	{
		int t = find(p[x]);
		d[x] += d[p[x]];
		p[x] = t;
	}
	return p[x];
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1 ; i <= n ; ++i)
		p[i] = i;

	int res = 0;
	while (m--)
	{
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);

		if ((x > n) || (y > n))
			++res;
		else
		{
			int px = find(x), py = find(y);
			if (t == 1)
			{
				if (px == py)
				{
					if ((d[x] - d[y]) % 3)
						++res;
				}
				else
				{
					p[px] = py;
					d[px] = d[y] - d[x];
				}
			}
			else
			{
				if (px == py)
				{
					if ((d[x] - d[y] - 1) % 3)
						++res;
				}
				else
				{
					p[px] = py;
					d[px] = d[y] + 1 - d[x];
				}
			}
		}
	}

	printf("%d\n", res);
	
	return 0;
}
