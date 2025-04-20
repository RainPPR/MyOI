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
#include<map>
//#include<bits/stdc++.h>
//#include<windows.h>
//#include<conio.h>
using namespace std;
typedef long long int ll;
ll getdec()
{
	int jinzhi = 0;
	scanf("%d", &jinzhi);
	if (jinzhi == 10)
	{
		int numj = 0;
		scanf("%d", &numj);
		return numj;
	}
	else
	{
		map<char, int>a;
		for (int i = 0 ; i < 9 ; i++)
		{
			a[char(i + '0')] = i;
		}
		for (int i = 0 ; i <= 5 ; i++)
		{
			a[char(i + 'A')] = i + 10;
			a[char(i + 'a')] = i + 10;
		}
		//
		cin.get();
		char strj[102] = {0};
		scanf("%s", strj);
		int i = 0;
		ll num = 0;
		for (int j = strlen(strj) - 1 ; j >= 0 ; j--)
		{
			int t = a[strj[j]];
			//printf("%d. %d * ( %d ^ %d ) \n", j, t, jinzhi, i);	//输出计算过程
			num += t * pow(jinzhi, i++);
		}
		return num;
	}
	return -1;
}
ll getfan(ll n)
{
	ll nt = 0;
	while (n)
	{
		nt = nt * 10 + n % 10;
		n /= 10;
	}
	return nt;
}
ll ishw(ll n)
{
	return n == getfan(n);
}
ll getstep(ll n, ll c)
{
	if (c > 30)
	{
		return -1;
	}
	if (ishw(n))
	{
		return c;
	}
	else
	{
		return getstep(n + getfan(n), ++c);
	}
}
int main()
{
	ll step = 0;
	step = getstep(getdec(), 0);
	if ((step == -1) || (step > 30))
	{
		printf("Impossible!\n");
	}
	else
	{
		printf("STEP=%lld\n", step);
	}
	return 0;
}
