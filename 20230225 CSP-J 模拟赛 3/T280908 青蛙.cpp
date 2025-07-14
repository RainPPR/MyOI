#include <cstdio>

using namespace std;

const int N = 1e5 + 10;
int sum[N];

int main()
{
	int n, k, x;
	
	scanf("%d %d", &n, &k);
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", &x);
		sum[i] = (sum[i - 1] + x) % x;
	}
	
	int cnt = 0;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = i ; j <= n ; ++j)
			if ((sum[j] - sum[i - 1]) % k == 0)
				++cnt;
	
	printf("%d", cnt);
	return 0;
}
