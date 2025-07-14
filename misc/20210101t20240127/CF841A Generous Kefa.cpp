#include <cstdio>

using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	char str[110] = {0};
	scanf("%s", str);

	int tong[256] = {0};
	for (int i = 0 ; i < n ; ++i)
	{
		int &t = tong[(int)str[i]];
		++t;

		if (t > k)
		{
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;
}
