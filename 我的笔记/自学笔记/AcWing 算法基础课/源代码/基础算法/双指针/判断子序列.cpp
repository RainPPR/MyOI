#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int a[N], b[N];
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0 ; i < n ; ++i)
		scanf("%d", a + i);
	for (int i = 0 ; i < m ; ++i)
		scanf("%d", b + i);
	for (int i = 0, j = 0; i < n ; ++i)
	{
		while ((j < m) && (a[i] != b[j]))
			++j;
		if (j++ < m)
			continue;
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}
