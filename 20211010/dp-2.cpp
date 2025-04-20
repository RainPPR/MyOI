#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1000000] = {0};
int dp[1000000] = {0};
int main()
{
	int n = 0;
	cin >> n;
	int mmax = -2100000000;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
		dp[i] = 1;
		for(int j = 0 ; j < i ; j++)
		{
			if(a[i] > a[j])
			{
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		if(dp[i] > mmax)
		{
			mmax = dp[i];
		}
	}
	cout << mmax << endl;
	return 0;
}
