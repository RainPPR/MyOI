#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n = 0;
	int a[100] = {0};
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		for (int i = 0 ; i < n ; i++)
		{
			scanf("%d", a + i);
		}
		bool isyes = true;
		for (int i = 0 ; (i < n - 1) && isyes ; i++)
		{
			int now = a[i];
			for (int j = i + 1 ; (j < n) && isyes ; j++)
			{
				if (a[j] < a[i])
				{
					if (a[j] < now)
					{
						now = a[j];
					}
					else
					{
						isyes = false;
					}
				}
			}
		}
		if (isyes)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
		memset(a, 0, sizeof(a));
	}
	return 0;
}
