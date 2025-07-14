#include <cstdio>
#include <set>

using namespace std;

const int N = 1e5 + 10;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	while (a > b)
		a -= b;

	set<int> visit;

	int pos = 0;
	while (1)
	{
		int ans = a / b;
		if ((pos != 0) && (ans == c))
		{
			printf("%d", pos);
			return 0;
		}

		a = (a - ans * b) * 10;

		if (visit.count(a))
			break;
		else
			visit.insert(a);

		++pos;
	}

	printf("-1");
	return 0;
}
