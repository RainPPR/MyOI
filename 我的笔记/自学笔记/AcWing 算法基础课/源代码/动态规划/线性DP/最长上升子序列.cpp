#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
typedef pair<int, int> PI;
const int N = 1010;
int n;
int a[N], f[N];
int g[N];
int main()
{
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d", a + i);
	int res = 0, ans = 0;
	for (int i = 1 ; i <= n ; ++i)
	{
		f[i] = 1;	// 上升子序列中只有a[i]一个数
		g[i] = 0;
		for (int j = 1 ; j < i ; ++j)
			if ((a[j] < a[i]) && (f[j] + 1 > f[i]))
			{
				f[i] = f[j] + 1;
				g[i] = j;
			}
		if (f[i] > res)
		{
			res = f[i];
			ans = i;
		}
	}
	printf("%d\n", res);
	stack<PI> st;
	for (int i = ans ; i != 0 ; i = g[i])
	{
		st.push({i, a[i]});
	}
	while (st.size())
	{
		PI tp = st.top();
		st.pop();
		printf("[%d] %d\n", tp.first, tp.second);
	}
	return 0;
}
