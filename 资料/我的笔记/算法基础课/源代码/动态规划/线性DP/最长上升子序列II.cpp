#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N], q[N];	// 结尾min
int main()
{
	scanf("%d", &n);
	for (int i = 0 ; i < n ; ++i)
		scanf("%d", a + i);
	int len = 0;
	q[0] = -2e9;
	for (int i = 0 ; i < n ; ++i)
	{
		int l = 0, r = len;	// 小于a[i]的最大数
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (q[mid] < a[i])
				l = mid;
			else
				r = mid - 1;
		}
		len = max(len, r + 1);
		q[r + 1] = a[i];
	}
	printf("%d", len);
	return 0;
}

