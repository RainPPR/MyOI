#include<cstdio>
const int N = 200005, K = 55;
int n, k, p, ans, sum[K], num[K], last[K];
int main()
{
	scanf("%d%d%d", &n, &k, &p);
	int now = 0;
	for(int i = 1; i <= n; i++)
	{
		int c, v;
		scanf("%d%d", &c, &v);
		if(v <= p) now = i;
		if(now >= last[c])
			sum[c] = num[c];
		last[c] = i;
		ans += sum[c];
		num[c]++;
	}
	printf("%d\n", ans);
	return 0;
}
