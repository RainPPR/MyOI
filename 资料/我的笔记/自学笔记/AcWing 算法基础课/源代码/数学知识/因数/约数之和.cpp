#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
	int d = 0;
	scanf("%d", &d);
	unordered_map<int, int> primes;
	while (d--)
	{
		int x = 0;
		scanf("%d", &x);
		for (int i = 2 ; i <= x / i ; ++i)
			while (x % i == 0)
			{
				x /= i;
				primes[i]++;
			}
		if (x > 1)
			primes[x]++;
	}
	long long ans = 1;
	for (auto p : primes)
	{
		int a = p.first, b = p.second;
		long long t = 1;
		while (b--)
			t = (t * a + 1) % mod;
		ans = ans * t % mod;
	}
	cout << ans << endl;
	return 0;
}
