#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int n = 0;
int a[N];
int tong[100001];
int main()
{
	scanf("%d", &n);
	for (int i = 0 ; i < n ; ++i)
		scanf("%d", a + i);
	int ans = 0;
	for (int i = 0, j = 0 ; i < n ; ++i)
	{
		tong[a[i]]++;
		while ((j < i) && (tong[a[i]] > 1))
			tong[a[j++]]--;
		ans = max(ans, i - j + 1);
	}
	printf("%d", ans);
	return 0;
}
