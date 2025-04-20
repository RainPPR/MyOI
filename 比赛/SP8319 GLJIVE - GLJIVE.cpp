#include <cstdio>

using namespace std;

int ABS(const int &n)
{
	return (n < 0) ? -n : n;
}

int main()
{
	int s[11];
	s[0] = 0;

	for (int i = 1 ; i <= 10 ; ++i)
	{
		scanf("%d", s + i);
		s[i] += s[i - 1];
	}

	int min_sub = 2e9, min_sum = 0;
	for (int i = 1 ; i <= 10 ; ++i)
	{
		int sub = ABS(s[i] - 100);
		if (sub <= min_sub)
			min_sub = sub, min_sum = s[i];
	}

	printf("%d\n", min_sum);
	return 0;
}
