#include<iostream>
using namespace std;
int main()
{
	int num[10000] = {0};
	int n = 0;
	scanf("%d", &n);
	for (int i = 0 ; i < n ; i++)
	{
		scanf("%d", num + i);
	}
	int zero = 0;
	int unze = 1;
	while (zero < n)
	{
		if (num[zero] == 0)
		{
			while ((num[unze] == 0) && (unze < n))
			{
				unze++;
			}
			if (unze < n)
			{
				swap(num[unze], num[zero]);
			}
			else
			{
				break;
			}
		}
		else
		{
			zero++;
			unze++;
		}
	}
	for (int i = 0 ; i < n ; i++)
	{
		cout << num[i] << " ";
	}
	return 0;
}
