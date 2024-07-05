#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100010,	// ����������м�������
          M = N * 2;	// �ߵ�����������Ľ��������
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
// DFS��������uΪ���������е������
int ans = N + 1;
int n;
bool st[N];
int dfs(int u)
{
	// ���Ϊ�Ѿ���������
	st[u] = true;
	int sum = 1,	// ��ǰ�����Ĵ�С
	    res = 0;	// ÿһ����ͨ��Ĵ�С�����ֵ
	for (int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			int s = dfs(j);	// ��ǰ�����Ĵ�С
			res = max(res, s);
			sum += s;
		}
	}
	res = max(res, n - sum);
	ans = min(ans, res);
	return sum;
}
int main()
{
	init();
	scanf("%d", &n);
	for (int i = 0 ; i < n - 1 ; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		add_double(a, b);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
