#include<iostream>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
char p[N], s[M];
int ne[N];

int main()
{
	scanf("%d", &n);
	scanf("%s", p + 1);
	scanf("%d", &m);
	scanf("%s", s + 1);
	
	// 求next
	for (int i = 2, j = 0 ; i <= n ; ++i)
	{
		while (j && (p[i] != p[j + 1]))
			j = ne[j];
		if (p[i] == p[j + 1])
			++j;
		ne[i] = j;
	}
	
	// KMP匹配过程
	for (int i = 1, j = 0 ; i <= m ; ++i)
	{
		while (j && (s[i] != p[j + 1]))
			j = ne[j];
		if (s[i] == p[j + 1])
			++j;
		if (j == n)
		{
			// 匹配成功
			printf("%d ", i - n);
			j = ne[j];
		}
	}
	
	return 0;
}
