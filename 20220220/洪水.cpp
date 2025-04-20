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
int n = 0, m = 0;
int ux[4] = {-1, 0, 0, 1};
int uy[4] = {0, -1, 1, 0};
short dp[502][502] = {0};
void dfs(int i, int j)
{
	dp[i][j] = 1;
	for (int k = 0 ; k < 4 ; k++)
	{
		int x = i + ux[k];
		int y = j + uy[k];
		if ((x >= 0) && (y >= 0) && (x <= n + 1) && (y <= m + 1) && (dp[x][y] == 0))
		{
			dfs(x, y);
		}
	}
	return;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= n ; i++)
	{
		char str[502] = {0};
		scanf("%s",str);
		for (int j = 1 ; j <= m ; j++)
		{
			char c = str[j-1]-'0';
			if (c == 0)
			{
				dp[i][j] = 0;
			}
			else
			{
				dp[i][j] = -1;
			}
		}
	}
	dfs(0, 0);
	int count = 0;
	for (int i = 0 ; i <= n + 1 ; i++)
	{
		for (int j = 0 ; j <= m + 1 ; j++)
		{
			if(dp[i][j] == 0)
			{
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
