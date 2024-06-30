#include<cstdio>
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];	// father

// 返回 x 所在集合的编号（祖宗结点）
int find(int x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d %d", &n, &m);

	// 初始化，假定节点编号是 1 ~ n
	for (int i = 1 ; i <= n ; ++i)
		p[i] = i;

	while (m--)
	{
		char op[2];
		int a, b;
		scanf("%s %d %d", op, &a, &b);
		if (op[0] == 'M')
			// 合并 a 和 b 所在的两个集合
			p[find(a)] = find(b);
		else if (find(a) == find(b))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
