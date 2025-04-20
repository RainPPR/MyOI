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
typedef long long int ll;
class op
{
	private:
		ll n = 0;
		ll num[1000000] = {0};
	public:
		op()
		{
			n = 0;
		}
		~op()
		{
			n = 0;
		}
		void in(ll np)
		{
			num[n++] = np;
		}
		void out()
		{
			for (ll i = n - 1 ; i >= 1 ; i--)
			{
				cout << num[i] << "+";
			}
			cout << num[0] << endl;
		}
		void reset()
		{
			n = 0;
			memset(num, 0, sizeof(num));
		}
};
ll fb[1000000] = {0};
ll fc = 2;
ll setfb(ll c)
{/*
	fc = 2;
	fb[0] = 0;
	fb[1] = 1;
	fb[2] = 1;*/
	while(fb[fc] < c)
	{
		fc++;
		fb[fc] = fb[fc - 1] + fb[fc - 2];
	}
	for (ll i = fc ; i >= 1 ; i--)
	{
		if (fb[i] < c)
		{
			return i + 1;
		}
	}
	return fc;
}
op opt;
int main()
{
	fc = 2;
	fb[0] = 0;
	fb[1] = 1;
	fb[2] = 1;
	//
	ll t = 0;
	cin >> t;
	while (t--)
	{
		opt.reset();
		ll n = 0;
		cin >> n;
		cout << n << "=";
		ll c = setfb(n);
		for (ll i = c ; i >= 1 ; i--)
		{
			if (n - fb[i] >= 0)
			{
				opt.in(fb[i]);
				n -= fb[i];
			}
		}
		if (n != 0)
		{
			opt.in(fb[n]);
		}
		opt.out();
	}
	return 0;
}
