#include <cstdio>
#include <unordered_map>

const int N = 110;
long long a[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0 ; i < n ; ++i)
		scanf("%lld", a + i);

	std::unordered_map<long long, int> times;
	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < n ; ++j)
			for (int k = 0 ; k < n ; ++k)
				++times[a[i] * a[j] + a[k]];

	long long cnt = 0;
	for (int d = 0 ; d < n ; ++d)
		if (a[d] != 0)
			for (int e = 0 ; e < n ; ++e)
				for (int f = 0 ; f < n ; ++f)
					cnt += times[a[d] * (a[e] + a[f])];

	printf("%lld\n", cnt);
	return 0;
}
