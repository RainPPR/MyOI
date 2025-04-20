#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 5e6 + 10;

const int MT[13] = {0, 0, 2678400, 5184000, 7862400, 10454400, 13132800, 15724800, 18403200, 21081600, 23673600, 26352000, 28944000};

struct Time
{
	int a, b, c, d, e, f;
	int key;

	Time()
	{
		a = b = c = d = e = f = 0;
	}
	Time(int _a, int _b, int _c, int _d, int _e, int _f)
	{
		a = _a, b = _b, c = _c, d = _d, e = _e, f = _f;
	}

	int Key()
	{
		return key = f + e * 60 + d * 60 * 60 + c * 60 * 60 * 24 + MT[b];
	}
};

int main()
{
	cin.tie(0);

	int n, m;
	scanf("%d %d", &n, &m);

	queue<Time> q;

	Time t;
	char *str = new char[N];

	while (~scanf("%d-%d-%d %d:%d:%d:", &t.a, &t.b, &t.c, &t.d, &t.e, &t.f))
	{
		cin.getline(str, N);

		t.Key();
		q.push(t);

		while (q.size() && t.key - q.front().key >= n)
			q.pop();

		if (q.size() >= m)
		{
			printf("%04d-%02d-%02d %02d:%02d:%02d\n", t.a, t.b, t.c, t.d, t.e, t.f);
			return 0;
		}
	}

	printf("-1\n");
	return 0;
}
