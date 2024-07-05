#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N = 100005;
int n, m, q, odd[N], even[N];
vector<int> v[N];
void bfs()
{
	memset(odd, 0x3f, sizeof(odd));
	memset(even, 0x3f, sizeof(even));
	queue<int> q, qd;
	for(int i = 0; i < v[1].size(); i++)
	{
		odd[v[1][i]] = 1;
		q.push(v[1][i]); qd.push(1);
	}
	while(!q.empty())
	{
		int x = q.front(), l = qd.front();
		q.pop(); qd.pop();
		for(int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			if(l % 2 == 0)
			{
				if(odd[y] > l + 1)
				{
					odd[y] = l + 1;
					q.push(y); qd.push(odd[y]);
				}
			}
			else
			{
				if(even[y] > l + 1)
				{
					even[y] = l + 1;
					q.push(y); qd.push(even[y]);
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs();
	for(int i = 1; i <= q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if(y % 2 == 0)
		{
			if(even[x] > y) puts("No");
			else puts("Yes");
		}
		else
		{
			if(odd[x] > y) puts("No");
			else puts("Yes");
		}
	}
	return 0;
}
