#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1e6 + 1;
int a[MAXN];
int n;
// 交换
void Swap(int &a, int &b)
{
	a ^= b, b ^= a, a ^= b;
}
// 快速排序
void quick_sort(int *q, int l, int r)
{
	if (l < r)
	{
		// 确定分界点
		int x = q[l + r >> 1];
		// 划分为两个区间，前面的所有数都<=x，后面的所有数都>=x
		int i = l - 1, j = r + 1;
		while (1)
		{
			do
				++i;
			while (q[i] < x);
			do
				--j;
			while (q[j] > x);
			if (i < j)
				Swap(q[i], q[j]);
			else
				break;
		}
		// 递归处理左右两段
		quick_sort(q, l, j);
		quick_sort(q, j + 1, r);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0 ; i < n ; ++i)
		scanf("%d", a + i);
	quick_sort(a, 0, n - 1);
	for (int i = 0 ; i < n ; ++i)
		printf("%d ", a[i]);
	return 0;
}
