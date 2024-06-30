#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 12010, M = 2010;

int n,	// ��Ʒ��
    m;	// ����������
int v[N],	// ��Ʒ�����
    w[N];	// ��Ʒ�ļ�ֵ
int f[N];

int main()
{
	scanf("%d %d", &n, &m);

	int cnt = 0;
	for (int i = 1 ; i <= n ; ++i)
	{
		int a, b, s;
		scanf("%d %d %d", &a, &b, &s);
		cout << a << " " << b << " " << s << endl;
		int k = 1;
		while (k <= s)
		{
			++cnt;
			v[cnt] = a * k;
			w[cnt] = b * k;
			s -= k;
			k <<= 1;
		}
		if (s > 0)
		{
			++cnt;
			v[cnt] = a * s;
			w[cnt] = b * s;
		}
	}

	n = cnt;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = m ; j >= v[i] ; --j)
			f[j] = max(f[j], f[j - v[i]] + w[i]);

	printf("%d", f[m]);

	return 0;
}
