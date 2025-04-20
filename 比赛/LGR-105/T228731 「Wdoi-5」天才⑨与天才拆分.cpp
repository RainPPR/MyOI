#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<ctime>
//#include<windows.h>
//#include<conio.h>
//#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t = 0;
	scanf("%d", &t);
	int k = 0;
	char str[20] = {0};
	while (t--)
	{
		scanf("%d %s", &k, str);
		if (k == 1)
		{
			printf("aya\n");
		}
		else if (strlen(str) % k == 0)
		{
			bool ok = true;
			for (int i = 0 ; i < strlen(str) ; i++)
			{
				if (str[i] != '9')
				{
					printf("baka\n");
					ok = false;
					break;
				}
			}
			if (ok)
			{
				printf("aya\n");
			}
		}
		else
		{
			printf("baka\n");
		}
	}
	return 0;
}
