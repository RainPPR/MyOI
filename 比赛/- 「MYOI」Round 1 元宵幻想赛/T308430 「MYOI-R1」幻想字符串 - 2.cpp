#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int S = 1e4 + 10;

int main()
{
	int n;
	char str[S];

	scanf("%d", &n);

	while (n--)
	{
		scanf("%s", str);

		int len = strlen(str);

		sort(str, str + len);

		int ans = 0;
		for (int i = 0 ; i < len / 2 ; ++i)
			ans -= str[i];
		for (int i = (len + 1) / 2 ; i < len ; ++i)
			ans += str[i];

		printf("%d\n", ans);
	}

	return 0;
}
