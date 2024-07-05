#include <cstdio>

using namespace std;

int main()
{
	int n, a, res;
	scanf("%d", &n);
	
	while (n--)
	{
		scanf("%d", &a);
		
		res = a;
		for (int i = 2 ; i <= a / i ; ++i)
			if (a % i == 0)
		{
			res = res / i * (i - 1);
			while (a % i == 0)
				a /= i;
		}
		if (a > 1)
			res = res / a * (a - 1);
		
		printf("%d\n", res);
	}
	
	return 0;
}
