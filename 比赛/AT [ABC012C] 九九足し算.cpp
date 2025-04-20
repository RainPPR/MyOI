#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	n = 2025 - n;

	set<pair<int, int> > v;
	for (int i = 1 ; i <= n / i ; ++i)
	{
		int back = n / i;
		if ((i < 10) && (back < 10) && (n % i == 0))
		{
			v.emplace(i, back);
			v.emplace(back, i);
		}
	}

	for (pair<int, int> i : v)
		printf("%d x %d\n", i.first, i.second);

	return 0;
}
