#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1000001] = {0};
int dp[1000001] = {0};
int main()
{
	int n = 0;
	cin >> n;
	int sum = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		dp[i] = max(a[i],dp[i-1]+a[i]);
		sum = max(dp[i],sum);
	}
	cout << sum << endl;
	return 0;
}
