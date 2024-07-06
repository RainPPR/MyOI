#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1e6 + 1;
int a[MAXN];
int n;
// ����
void Swap(int &a, int &b)
{
	a ^= b, b ^= a, a ^= b;
}
// ��������
void quick_sort(int *q, int l, int r)
{
	if (l < r)
	{
		// ȷ���ֽ��
		int x = q[l + r >> 1];
		// ����Ϊ�������䣬ǰ�����������<=x���������������>=x
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
		// �ݹ鴦����������
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
