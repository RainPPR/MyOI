#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int p[N];

// �ýṹ��洢ͼ
struct Edge
{
	int a, b, w;

	bool operator< (const Edge &W)const
	{
		return w < W.w;
	}
} edges[N];

// ���鼯-��������
int find(int x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

int main()
{
	// ����
	scanf("%d %d", &n, &m);
	int a, b, w;
	for (int i = 0 ; i < m ; ++i)
	{
		scanf("%d %d %d", &a, &b, &w);
		edges[i] = {a, b, w};
	}

	// ����
	sort(edges, edges + m);

	// ��ʼ�����鼯
	for (int i = 1 ; i <= n ; ++i)
		p[i] = i;

	// ��С����ö�����б�
	int res = 0, cnt = 0;
	for (int i = 0 ; i < m ; ++i)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;

		// ��������
		a = find(a), b = find(b);

		// �������ͨ
		if (a != b)
		{
			res += w, ++cnt;
			// �ϲ����鼯
			p[a] = b;
		}
	}

	// ���
	if (cnt < n - 1)
		printf("impossible\n");
	else
		printf("%d\n", res);
	return 0;
}
