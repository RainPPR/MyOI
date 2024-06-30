#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;

int n, m;
int g[N][N];	// ����ͼ���ڽӾ���洢
int dist[N];	// ÿ���㵽��ͨ��ľ���
bool st[N];		// ������Ƿ�����ͨ����

int prim()
{
	memset(dist, 0x3f, sizeof dist);

	int res = 0;	// ���бߵĳ���֮��
	for (int i = 0 ; i < n ; ++i)
	{
		int t = -1;
		for (int j = 1 ; j <= n ; ++j)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;

		// ͼ����ͨ��û����С������
		if (i && dist[t] == INF)
			return INF;
		if (i)				// ������ǵ�һ����
			res += dist[t];	// ����м����

		// ���¾���
		for (int j = 1 ; j <= n ; ++j)
			dist[j] = min(dist[j], g[t][j]);

		// ������ͨ��
		st[t] = true;
	}

	return res;
}

int main()
{
	// ��ʼ������Ϊ������
	memset(g, 0x3f, sizeof g);

	// ����
	scanf("%d %d", &n, &m);

	int a, b, c;
	while (m--)
	{
		scanf("%d %d %d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);
	}

	// Prim�㷨
	int t = prim();

	// ���
	if (t == INF)
		printf("impossible\n");
	else
		printf("%d\n", t);
	return 0;
}
