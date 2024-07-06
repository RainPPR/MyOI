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
int cnt[N];		// ��1�ŵ��ߵ�ÿ�������̾����������ı���
bool st[N];		// ������Ƿ��ڶ��е��У������ظ��洢

void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

int spfa()
{
	queue<int> q;
	for (int i = 1 ; i <= n ; ++i)
	{
		q.push(i);
		st[i] = true;
	}

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
				cnt[j] = cnt[t] + 1;

				if (cnt[j] >= n)
					return true;
				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return false;
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
	printf(t ? "Yes" : "No");

	return 0;
}
