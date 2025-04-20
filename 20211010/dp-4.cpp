#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int dp[10001][10001] = {0};
int main()
{
	int n = 0;
	cin >> n;
	int a[10001] = {0};
	int b[10001] = {0};
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i] >> b[i];
	}
	int m = 0;
	cin >> m;
	//
	for(int i = 1 ; i <= n ; i++)
	{
		if(i >= b[1])
		{
			dp[1][i] = a[1];
		}
		else
		{
			dp[1][i] = 0;
		}
	}
	for(int i = 2 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(j >= b[i])
			{
				dp[i][j] = max(dp[i-1][j],a[i]+dp[i-1][j-b[i]]);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}

