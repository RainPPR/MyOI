#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 500005;
int n, d, k, x[N], s[N], p[N];
long long f[N];
bool check(int len)
{
	int now = 0, head = 1, tail = 0, r = len + d, l = max(d-len, 1);
	for(int i = 1; i <= n; i++)
	{
		while(x[now] <= x[i] - l)
		{
			if(f[now] <= -1e9)
			{
				now++;
				continue;
			}
			while(head <= tail && f[now] >= f[p[tail]]) tail--;
			p[++tail] = now;
			now++;
		}
		while(head <= tail && x[p[head]] < x[i] - r) head++;
		if(head <= tail) f[i] = f[p[head]] + s[i];
		else f[i] = -1e9;
		if(f[i] >= k) return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d%d", &n, &d, &k);
	int l = 0, r = 0;
	long long tot = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x[i], &s[i]);
		r = max(r, x[i]);
		tot += max(0, s[i]);
	}
	if(tot < k)
	{
		puts("-1");
		return 0;
	}
	while(l < r)
	{
		int m = (l + r) >> 1;
		if(check(m)) r = m;
		else l = m + 1;
	}
	printf("%d\n", l);
	return 0;
}
