#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<string.h>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
//#include<bits/stdc++.h>
//#include<windows.h>
//#include<conio.h>
using namespace std;
int n = 0;
int map[50][50] = {0};
int main()
{
	scanf("%d", &n);
	int x = 1;			//i行
	int y = n / 2 + 1;	//j列
	for (int i = 1 ; i <= n*n ; i++)
	{
		map[x][y] = i;
		//printf("map[%d][%d] = %d;\n", x, y, i);		//输出位置
		if ((x == 1) && (y != n))		//1.
		{
			x = n;
			y = y + 1;
		}
		else if ((x != 1) && (y == n))	//2.
		{
			x = x - 1;
			y = 1;
		}
		else if ((x == 1) && (y == n))	//3.
		{
			x = x + 1;
		}
		else
		{
			if (map[x - 1][y + 1] == 0)		//4.
			{
				x = x - 1;
				y = y + 1;
			}
			else
			{
				x = x + 1;
			}
		}
	}
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
