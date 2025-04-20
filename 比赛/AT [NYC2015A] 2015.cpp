#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	string bin;
	while (n)
	{
		bin += (n & 1) + '0';
		n >>= 1;
	}

	string rbin = bin;
	reverse(rbin.begin(), rbin.end());

	if (bin == rbin)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
