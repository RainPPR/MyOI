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
		ans = ans * (p.second + 1) % mod;
	cout << ans << endl;
	return 0;
}
