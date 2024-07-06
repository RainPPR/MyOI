#include<iostream>
#include<cstdio>
using namespace std;
const int N = 100010;
int n, m;
int s[N];
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= n ; ++i)
	{
		int t = 0;
		scanf("%d", &t);
		s[i] = s[i - 1] + t;
	}
	while (m--)
	{
		int l = 0, r = 0;
		scanf("%d %d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}
	return 0;
}
