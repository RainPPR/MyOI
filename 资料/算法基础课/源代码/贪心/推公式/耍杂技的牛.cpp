#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 5e4 + 10;
int n, w, s;
PII cow[N];
int main()
{
	scanf("%d", &n);
	for (int i = 0 ; i < n ; ++i)
	{
		scanf("%d %d", &w, &s);
		cow[i] = {w + s, w};
	}
	sort(cow, cow + n);
	int res = -2e9, sum = 0;
	for (int i = 0 ; i < n ; ++i)
	{
		w = cow[i].second, s = cow[i].first - w;
		res = max(res, sum - s);
		sum += w;
	}
	printf("%d\n", res);
	return 0;
}
