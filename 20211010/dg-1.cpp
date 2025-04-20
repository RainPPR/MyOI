#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll dp[1000000] = {0};
int main()
{
	int n = 0;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3 ; i <= n ; i++)
	{
		dp[i] = dp[i-1]+dp[i-2];
	}
	cout << dp[n] << endl;
	return 0;
}
