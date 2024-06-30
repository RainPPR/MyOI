# ORGANIZATOR
```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const int M = 2 * 1e6 + 10;
int tong[M], n, x;
template<class T>
T MAX(T a, T b)
{
	return (a > b) ? a : b;
}
int main()
{
	scanf("%d", &n);
	int maxn = -1e9;
	for (int i = 0 ; i < n ; ++i)
	{
		scanf("%d", &x);
		maxn = MAX(maxn, x);
		tong[x]++;
	}
	ll ans = -1e9;
	for (int x = 1 ; x <= maxn ; ++x)
	{
		int cnt = 0;
		for (int j = x ; j <= maxn ; j += x)
			cnt += tong[j];
		if (cnt >= 2)
			ans = MAX(ans, (ll)cnt * x);
	}
	printf("%lld", ans);
	return 0;
}
```