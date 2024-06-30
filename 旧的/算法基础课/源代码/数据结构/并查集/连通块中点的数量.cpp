#include<cstdio>
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N], sz[N];

// ���� x ���ڼ��ϵı�ţ����ڽ�㣩
int find(int x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d %d", &n, &m);

	// ��ʼ�����ٶ��ڵ����� 1 ~ n
	for (int i = 1 ; i <= n ; ++i)
		p[i] = i, sz[i] = 1;

	while (m--)
	{
		char op[3];
		int a, b;
		scanf("%s", op);
		// �ϲ� a �� b ���ڵ���������
		if (op[0] == 'C')
		{
			scanf("%d %d", &a, &b);
			int fa = find(a), fb = find(b);
			if (fa != fb)   // a �� b �������
				sz[fb] += sz[fa], p[fa] = fb;
		}
		// ѯ�ʵ� a �͵� b �Ƿ���ͬһ����ͨ����
		else if (op[1] == '1')
		{
			scanf("%d %d", &a, &b);
			if (find(a) == find(b))
				printf("Yes\n");
			else
				printf("No\n");
		}
		// ѯ�ʵ� a ������ͨ���е������
		else
		{
			scanf("%d", &a);
			printf("%d\n", sz[find(a)]);
		}
	}
	return 0;
}
