// File: ¥��ͼ��.cpp

#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;

int tot;
int a[N];	// ԭ����
int tr[N];	// ��״����

int lowbit(const int x)
{
	return x & -x;
}

void add(const int x, const int c)
{
	for (int i = x ; i <= tot ; i += lowbit(i))
		tr[i] += c;
}

int sum(const int x)
{
	int res = 0;
	for (int i = x ; i ; i -= lowbit(i))
		res += tr[i];
	return res;
}

int Greater[N];	// ÿ����ǰ���ж��ٸ���������
int Lower[N];	// ÿ����ǰ���ж��ٸ���С����

int main()
{
	scanf("%d", &tot);
	for (int i = 1 ; i <= tot ; ++i)
		scanf("%d", a + i);

	for (int i = 1 ; i <= tot ; ++i)
	{
		int &y = a[i];
		Greater[i] = sum(tot) - sum(y);
		Lower[i] = sum(y - 1);
		add(y, 1);
	}

	memset(tr, 0, sizeof tr);

	long long r1 = 0, r2 = 0;
	for (int i = tot ; i ; --i)
	{
		int &y = a[i];
		r1 += (long long)Greater[i] * (sum(tot) - sum(y));
		r2 += (long long)Lower[i] * sum(y - 1);
		add(y, 1);
	}

	printf("%lld %lld", r1, r2);
	return 0;
}
