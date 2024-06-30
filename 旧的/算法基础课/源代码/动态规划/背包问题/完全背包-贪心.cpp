#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
struct node
{
	int v,	// 体积
	    w;	// 价值
	double wperv;	// 性价比
} a[N];
bool cmp(node a, node b)
{
	return (a.wperv == b.wperv) ? (a.v < b.v) : (a.wperv < b.wperv);
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d %d", &a[i].v, &a[i].w);
		a[i].wperv = double(a[i].w) / a[i].v;
	}
	sort(a + n, a + 1 + n, cmp);
	int ans = 0;
	for (int i = 1 ; i <= n ; ++i)
	{
		int v = a[i].v;
		int w = a[i].w;
		// 可以买m/v件，价值为(m/v)*w，体积为(m/v)*v;
		ans += (m / v) * w;
		m -= (m / v) * v;
	}
	printf("%d", ans);
	return 0;
}
