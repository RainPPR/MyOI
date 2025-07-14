#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int a[4];
	for (int i = 0 ; i < 4 ; ++i)
		scanf("%d", a + i);

	sort(a, a + 4);

	if ((a[0] == a[1]) && (a[2] == a[3]))
		printf("YES");
	else
		printf("NO");
	return 0;
}
