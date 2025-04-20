#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3e5 + 10;

int a, b, c;
int m;

pair<int, char> x[N];

int ans;

int main()
{
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d", &m);

	for (int i = 0 ; i < m ; ++i)
		scanf("%d %c", &x[i].first, &x[i].second);

	sort(x, x + m);

	int cnt = 0;
	long long ans = 0;
	for (int i = 0 ; i < m ; ++i)
	{
		if (x[i].second == 'A')
		{
			if (a)
				--a, ++cnt, ans += x[i].first;
			else if (c)
				--c, ++cnt, ans += x[i].first;
		}
		else
		{
			if (b)
				--b, ++cnt, ans += x[i].first;
			else if (c)
				--c, ++cnt, ans += x[i].first;
		}
	}

	printf("%d %lld", cnt, ans);
	return 0;
}
