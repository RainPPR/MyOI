#include<cstdio>
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

// �±���0�ĵ㣬��ʹ���ڵ㣬���ǿսڵ�
// son[][]�洢����ÿ���ڵ���ӽڵ�
// cnt[]�洢��ÿ���ڵ��β�ĵ�������
int son[N][26], cnt[N], idx;
char str[N];

// ����һ���ַ���
void insert(char str[])
{
	int p = 0;
	for (int i = 0 ; str[i] ; ++i)
	{
		int u = str[i] - 'a';
		if (!son[p][u])
			son[p][u] = ++idx;
		p = son[p][u];
	}
	++cnt[p];
}

// ��ѯ�ַ������ֵĴ���
int query(char str[])
{
	int p = 0;
	for (int i = 0 ; str[i] ; ++i)
	{
		int u = str[i] - 'a';
		if (!son[p][u])
			return 0;
		p = son[p][u];
	}

	return cnt[p];
}

int main()
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		char op[2];
		scanf("%s%s", op, str);
		if (op[0] == 'I')
			insert(str);
		else
			printf("%d\n", query(str));
	}

	return 0;
}
