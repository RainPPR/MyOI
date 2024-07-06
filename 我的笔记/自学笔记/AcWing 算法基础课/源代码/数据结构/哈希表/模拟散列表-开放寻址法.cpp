#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 2e5 + 3;
const int null = 0x3f3f3f3f;
int h[N];
inline int find(int x)	// 返回x所在位置；应该存储的位置
{
	int k = (x % N + N) % N;
	while ((h[k] != null) && (h[k] != x))
	{
		++k;
		if (k == N)
			k = 0;
	}
	return k;
}
int main()
{
	int n;
	scanf("%d", &n);
	memset(h, 0x3f, sizeof(h));
	while (n--)
	{
		char op[2];
		int x;
		scanf("%s %d", op, &x);
		if (op[0] == 'I')
			h[find(x)] = x;
		else if (h[find(x)] != null)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
