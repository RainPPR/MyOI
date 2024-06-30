#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 25, M = 105;
int n, h, p[N], m[N], v[N][M], t[N][M], f[5005];
int main()
{
	scanf("%d%d", &n, &h);
	for(int i = 1; i < n; i++)
		scanf("%d", &p[i]);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &m[i]);
		for(int j = 1; j <= m[i]; j++)
			scanf("%d%d", &v[i][j], &t[i][j]);
	}
	int mx = h;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m[i]; j++)
			for(int k = mx; k >= t[i][j]; k--)
				f[k] = max(f[k], f[k-t[i][j]] + v[i][j]);	
		mx -= p[i]; // 每增加一个山洞，可以采药的时间就会减少
	}
	int ans = 0;
	for(int i = 1; i <= h; i++)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}
