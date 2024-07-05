#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1e6 + 1;
int a[MAXN];
int t[MAXN];
int n;
// 归并排序
void merge_sort(int *q, int l, int r)
{
	if (l < r)
	{
		// 确定分界点
		int mid = l + r >> 1;
		// 递归排序左边和右边
		merge_sort(q, l, mid);
		merge_sort(q, mid + 1, r);
		// 归并，把两个有序的数组合并为一个有序的数组
		int c = 0;
		int i = l;
		int j = mid + 1;
		while ((i <= mid) && (j <= r))
			if (q[i] <= q[j])
				t[c++] = q[i++];
			else
				t[c++] = q[j++];
		while (i <= mid)
			t[c++] = q[i++];
		while (j <= r)
			t[c++] = q[j++];
		// 把归并完的数组放回原数组中
		for (i = l, j = 0; j < c; ++i, ++j)
			q[i] = t[j];
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0 ; i < n ; ++i)
		scanf("%d", a + i);
	merge_sort(a, 0, n - 1);
	for (int i = 0 ; i < n ; ++i)
		printf("%d ", a[i]);
	return 0;
}
