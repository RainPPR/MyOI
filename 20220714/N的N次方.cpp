#include<iostream>
using namespace std;
int getsize(long long n)
{
	int i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return i;
}
int main()
{
	//cout << LONG_LONG_MAX << endl;
	long long n = 0;
	while (~scanf("%d", &n))
	{
		long long ans = 1;
		for (int k = 1 ; k <= n ; k++)
		{
			ans *= n;
			while(getsize(ans) > 9)
			{
				ans /= 10;
			}
		}
		while (ans >= 10)
		{
			ans /= 10;
		}
		int c = int(ans);
		printf("%d\n", c);
	}
	return 0;
}
