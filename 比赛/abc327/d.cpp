#include <bits/stdc++.h>

using namespace std;

const int N = 200010, M = 400010;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool dfs(int u, int c)
{
	color[u] = c;

	for (int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if (!color[j])
		{
			if (!dfs(j, 3 - c))
				return false;
		}
		else if (color[j] == c)
			return false;
	}

	return true;
}

int main()
{
	scanf("%d %d", &n, &m);

	memset(h, -1, sizeof h);

    vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);

	for (int i = 0; i < m; ++i)
	{
		add(a[i], b[i]);
		add(b[i], a[i]);
	}

	// Ⱦɫ
	bool flag = true;
	for (int i = 1 ; i <= n ; ++i)
		if (!color[i])	// δ��Ⱦɫ
			if (!dfs(i, 1))
			{
				flag = false;
				break;
			}

	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
	
	return 0;
}