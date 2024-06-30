#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;
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

int h[N], w[N], e[N], ne[N], idx;	// ϡ��ͼ���ڽӱ�洢
int dist[N];	// ��1�ŵ��ߵ�ÿ�������̾���
bool st[N];		// ��������̾����Ƿ��Ѿ�ȷ��

void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

// ��� 1 �ŵ㵽 n �ŵ����̾���
int dijkstra()
{
	// ��ʼ������
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;

	// �ö�ά�������Ҿ�����̵ĵ�
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1});

	while (heap.size())
	{
		// ���� s �еģ�������̵ĵ�
		PII t = heap.top();
		heap.pop();

		int ver = t.second, distance = t.first;
		if (st[ver])	// ȷ������ s ��
			continue;
		st[ver] = true;

		// �� t �����������е�ľ���
		for (int i = h[ver] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({dist[j], j});
			}
		}
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
	// ��ʼ���ڽӱ�
	memset(h, -1, sizeof(h));

	// ����
	scanf("%d %d", &n, &m);
	int a, b, c;
	while (m--)
	{
		scanf("%d %d %d", &a, &b, &c);
		add(a, b, c);	// ���ڽӱ�洢�������ж��ر�
	}

	// ���Ż�Dijkstra
	int t = dijkstra();

	// ���
	printf("%d\n", t);

	return 0;
}
