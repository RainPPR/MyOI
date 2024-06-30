#include<cstdio>
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];	// father

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
		p[i] = i;

	while (m--)
	{
		char op[2];
		int a, b;
		scanf("%s %d %d", op, &a, &b);
		if (op[0] == 'M')
			// �ϲ� a �� b ���ڵ���������
			p[find(a)] = find(b);
		else if (find(a) == find(b))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
