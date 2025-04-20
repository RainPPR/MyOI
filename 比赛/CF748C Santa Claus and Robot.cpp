#include <cstdio>

using namespace std;

const int N = 2e5 + 10;

int ABS(const int &n)
{
	return (n < 0) ? -n : n;
}

struct point
{
	int x, y;
};

int getSub(point a, point b)
{
	return ABS(a.x - b.x) + ABS(a.y - b.y);
}

int main()
{
	int n;
	char str[N];
	scanf("%d", &n);
	scanf("%s", str);

	point robot = {0, 0};

	point last = {0, 0};
	point now = {0, 0};

	int cnt = 1;
	for (int i = 0 ; i < n ; ++i)
	{
		char c = str[i];

		last = now;
		switch (c)
		{
			case 'L':
				--now.y;
				break;
			case 'R':
				++now.y;
				break;
			case 'U':
				--now.x;
				break;
			case 'D':
				++now.x;
				break;
		}

		if (getSub(robot, last) + getSub(last, now) > getSub(robot, now))
			robot = last, ++cnt;
	}

	printf("%d", cnt);
	return 0;
}
