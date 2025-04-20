#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 5e3 + 10;

vector<int> edge[N];
int d[N];

int ans[N];

int main()
{
	int N, K, p, R;
	scanf("%d %d %d", &N, &K, &p);

	int x;
	while (p--)
	{
		scanf("%d", &x);
		++d[x];
		edge[0].push_back(x);
	}

	scanf("%d", &R);

	int v, s;
	for (int i = 0 ; i < R ; ++i)
	{
		scanf("%d %d", &v, &s);
		d[v] += s;
		while (s--)
		{
			scanf("%d", &x);
			edge[x].push_back(v);
		}
	}

	queue<int> q;
	q.push(0);
	while (q.size())
	{
		int now = q.front();
		q.pop();

		for (int i : edge[now])
		{
			--d[i];
			if (!d[i])
			{
				ans[i] = ans[now] + 1;
				q.push(i);
			}
		}
		edge[now].clear();
	}

	printf("%d", ans[K] - 1);
	return 0;
}
