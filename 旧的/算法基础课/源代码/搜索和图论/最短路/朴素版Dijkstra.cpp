#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;

// �������ֵ
inline int MAX(int a, int b)
{
	return (a > b) ? a : b;
}
// ������Сֵ
inline int MIN(int a, int b)
{
	return (a < b) ? a : b;
}

int n, m;		// n:���� m:����
int g[N][N];	// ����ͼ���ڽӾ���洢
int dist[N];	// ��1�ŵ��ߵ�ÿ�������̾���
bool st[N];		// ��������̾����Ƿ��Ѿ�ȷ��

// ��� 1 �ŵ㵽 n �ŵ����̾���
int dijkstra()
{
	// ��ʼ������
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;

	// ѭ�� n ��
	for (int i = 0 ; i < n ; ++i)
	{
		int t = -1;	// ���� s �еģ�������̵ĵ�
		for (int j = 1 ; j <= n ; ++j)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		st[t] = true;

		// ����Ѿ��ҵ����·���˳�
		if (t == n)
			break;

		// �� t �����������е�ľ���
		for (int j = 1 ; j <= n ; ++j)
			dist[j] = MIN(dist[j], dist[t] + g[t][j]);
	}

	// ���û��·��
	if (dist[n] == INF)
		// ���� -1
		return -1;
	// ���� 1 �ŵ㵽 n �ŵ�ľ���
	return dist[n];
}

int main()
{
	// ��ʼ���ڽӾ���
	memset(g, 0x3f, sizeof(g));

	// ����
	scanf("%d %d", &n, &m);
	int a, b, c;
	while (m--)
	{
		scanf("%d %d %d", &a, &b, &c);
		g[a][b] = MIN(g[a][b], c);	// ͼ�п��ܴ����رߺ��Ի�������������̵ı�
	}

	// ���ذ�Dijkstra
	int t = dijkstra();

	// ���
	printf("%d\n", t);

	return 0;
}
