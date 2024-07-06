#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, m;		// n:���� m:����

int h[N], w[N], e[N], ne[N], idx;
int dist[N];	// ��1�ŵ��ߵ�ÿ�������̾���
bool st[N];		// ������Ƿ��ڶ��е��У������ظ��洢

void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

// ��� 1 �ŵ㵽 n �ŵ����̾���
int spfa()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	queue<int> q;
	q.push(1);
	st[1] = true;

	while (q.size())
	{
		int t = q.front();
		q.pop();

		st[t] = false;

		for (int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}

	if (dist[n] == 0x3f3f3f3f)
		return -2;
	else
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
		add(a, b, c);
	}

	// SPFA
	int t = spfa();

	// ���
	if (t == -2)
		printf("impossible\n");
	else
		printf("%d\n", t);

	return 0;
}
