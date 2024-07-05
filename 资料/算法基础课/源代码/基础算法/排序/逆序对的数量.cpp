#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int t[N];
long long count = 0;
void merge_sort(int *q, int l, int r)
{
	if (l < r)
	{
		int mid = l + r >> 1;
		merge_sort(q, l, mid);
		merge_sort(q, mid + 1, r);
		int k = 0, i = l, j = mid + 1;
		while ((i <= mid) && (j <= r))
		{
			if (q[i] <= q[j])
				t[k++] = q[i++];
			else
			{
				t[k++] = q[j++];
				count += mid - i + 1;
			}
		}
		while (i <= mid)
			t[k++] = q[i++];
		while (j <= r)
			t[k++] = q[j++];
		for (i = 0, j = l; i < k; i++, j++)
			q[j] = t[i];
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 0 ; i < n ; i++)
		scanf("%d", a + i);
	merge_sort(a, 0, n - 1);
	cout << count << endl;
	return 0;
}
