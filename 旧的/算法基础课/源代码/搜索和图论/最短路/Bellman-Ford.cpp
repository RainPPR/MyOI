#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 510, M = 10010;

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

int n, m, k;	// n:���� m:���� �󲻳���k���ߵ���̾���
int dist[N];	// ��1�ŵ��ߵ�ÿ�������̾���
int backup[N];	// dist�ı���

// ���Զ���ṹ��洢ͼ���ߣ�
struct Edge
{
	int a, b, w;	// �� a �� b ��һ������Ϊ w �ı�
} edges[M];

// ��� 1 �ŵ㵽 n �ŵ㣬������ k ���ߵ���̾���
int bellman_ford()
{
	// ��ʼ������
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;

	// ���� k �Σ���Ҫ�����ߣ���ѭ�����Σ�
	for (int i = 0 ; i < k ; ++i)
	{
		// �� dist ���ݵ� backup ��
		// �����б��ݵĻ������ܻᷢ����������
		// ���ݣ��Ա�֤����ֻʹ����һ�ε����Ľ��
		memcpy(backup, dist, sizeof(dist));

		// ö�����б�
		for (int j = 0 ; j < m ; ++j)
		{
			// ����һ��ö�ٵ��������ȡ�����������д�ô����һ�㣩
			int a = edges[j].a;
			int b = edges[j].b;
			int w = edges[j].w;

			// ������̾���
			dist[b] = min(dist[b], backup[a] + w);
		}
	}

	// ���û��·��������
	if (dist[n] > 0x3f3f3f3f / 2)
		return -2;
	// ������̾���
	return dist[n];
}

int main()
{
	// ����
	scanf("%d %d %d", &n, &m, &k);

	// ���� m ����
	int a, b, w;
	for (int i = 0 ; i < m ; ++i)
	{
		scanf("%d %d %d", &a, &b, &w);
		edges[i] = {a, b, w};
	}

	// Bellman-Ford�㷨
	int t = bellman_ford();

	// ���
	if (t == -2)
		printf("impossible\n");
	else
		printf("%d\n", t);
	return 0;
}
