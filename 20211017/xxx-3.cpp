#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
int main()
{
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll n = 0;
	cin >> n;
	ll sum = 1;
	ll re = 1;
	for(ll i = 2 ; i <= n ; i++)
	{
		sum *= i;
		re *= sum%100;
		sum %= 10000000000;
	}
	cout << re << endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
