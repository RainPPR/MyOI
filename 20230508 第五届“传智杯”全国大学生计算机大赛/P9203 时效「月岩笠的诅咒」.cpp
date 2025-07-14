#include <cstdio>

using namespace std;

int main()
{
	long long a1, a2, b1, b2;
	scanf("%lld.%lld %lld.%lld", &a1, &a2, &b1, &b2);
	
	if (a2 == b2)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
