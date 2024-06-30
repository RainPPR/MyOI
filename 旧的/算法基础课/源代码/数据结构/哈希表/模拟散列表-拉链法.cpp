#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 3;
int h[N];
int e[N], ne[N], idx;
inline void insert(int x)
{
	int k = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx++;
}
inline bool find(int x)
{
	int k = (x % N + N) % N;
	for (int i = h[k] ; i != -1 ; i = ne[i])
		if (e[i] == x)
			return true;
	return false;
}
int main()
{
	int n;
	scanf("%d", &n);
	memset(h, -1, sizeof(h));
	while (n--)
	{
		char op;
		int x;
		scanf("%c %d", &op, &x);
		if (op == 'I')
			insert(x);
		else if (find(x))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
