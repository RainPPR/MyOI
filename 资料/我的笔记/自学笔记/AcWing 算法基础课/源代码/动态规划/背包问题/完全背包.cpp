#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;

int n,	// ��Ʒ��
    m;	// ����������
int v[N],	// ��Ʒ�����
    w[N];	// ��Ʒ�ļ�ֵ
int f[N];
int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1 ; i <= n ; ++i)
		scanf("%d %d", v + i, w + i);

	for (int i = 1 ; i <= n ; ++i)
		for (int j = v[i] ; j <= m ; ++j)
			f[j] = max(f[j], f[j - v[i]] + w[i]);

	printf("%d", f[m]);

	return 0;
}
