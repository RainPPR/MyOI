#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll qpow(ll a,ll b,ll m)
{
	ll res = 1;
	while(b > 0)
	{
		if(b&1)
		{
			res = res*a%m;
		}
		b >>= 1;
		a = a*a%m;
	}
	return res;
}
int main()
{
	cout << qpow(2,10,10000);
	return 0;
}
