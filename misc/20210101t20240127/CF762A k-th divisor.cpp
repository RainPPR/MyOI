#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<long long> vl;

vl get_divisors(long long n)
{
	vl res;

	for (long long i = 1 ; i <= n / i ; ++i)
	{
		if (n % i == 0)
		{
			res.push_back(i);
			if (i != n / i)
				res.push_back(n / i);
		}
	}

	sort(res.begin(), res.end());

	return res;
}

int main()
{
	long long n;
	int k;
	scanf("%lld %d", &n, &k);

	vl res = get_divisors(n);

	if (res.size() < k)
		printf("-1\n");
	else
		printf("%lld\n", res[k - 1]);
	return 0;
}
