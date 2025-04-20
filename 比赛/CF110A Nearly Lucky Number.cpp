#include <cstdio>

using namespace std;

int main()
{
	long long n;
	scanf("%lld", &n);

	int t, cnt = 0;
	while (n)
	{
		t = n % 10;
		if (t == 4 || t == 7)
			++cnt;
		n /= 10;
	}

	if (cnt == 0)
		printf("NO\n");
	else
	{
		bool flag = true;
		while (cnt)
		{
			t = cnt % 10;
			if (cnt != 4 && cnt != 7)
			{
				flag = false;
				break;
			}
			cnt /= 10;
		}

		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
