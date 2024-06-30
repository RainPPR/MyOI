#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 100010,	// ����������м�������
          M = N * 2;	// �ߵ�����������Ľ��������
int n, m;
int h[N],	// i�Ž���Ӧ�������ͷ
    e[M],	// ��һ�����ָ��ĵ�
    ne[M],	// ��һ�������±�
    idx;	// �������
// ��ʼ��
void init()
{
	idx = 0;
	memset(h, -1, sizeof(h));
}
// ����һ��aָ��b��
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
// ����һ�� a <-> b �ı�
void add_double(int a, int b)
{
	add(a, b);
	add(b, a);
}
// ����xָ������бߣ����ظ���
int geteg(int x)
{
	int count = 0;
	for (int i = h[x] ; i != -1 ; i = ne[i])
	{
		// ��ʱ������һ���ߣ�x -> e[i]
		count++;
		// ��������
	}
	return count;
}
// BFS
int d[N];
int bfs()
{
	memset(d, -1, sizeof(d));
	queue<int> q;
	q.push(1);
	d[1] = 0;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		for (int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1)
			{
				d[j] = d[t] + 1;
				q.push(j);
			}
		}
	}
	return d[n];
}
int main()
{
	init();
	scanf("%d %d", &n, &m);
	for (int i = 0 ; i < m ; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		add(a, b);
	}
	cout << bfs() << endl;
	return 0;
}
