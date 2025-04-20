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
using namespace std;
typedef long long ll;
int main()
{
	ll n = 0;
	ll c = 0;
	ll num[1000] = {0};
	cin >> n >> c;
	for (ll i = 0 ; i < n ; i++)
	{
		cin >> num[i];
	}
	//
	ll count = 0;
	for (ll i = 0 ; i < n ; i++)
	{
		for (ll j = 0 ; j < n ; j++)
		{
			if ((i != j) && ((num[i] - num[j]) == c))
			{
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
