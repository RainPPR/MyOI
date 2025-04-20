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
//#include<bits/stdc++.h>
//#include<windows.h>
//#include<conio.h>
using namespace std;
struct at
{
	int *num = new int[10000001];
	int c = 0;
	void in(int n)
	{
		num[++c] = n;
	}
	void out()
	{
		for(int i = 1 ; i <= c; i++)
		{
			printf("%d\n",num[i]);
		}
	}
	int get(int i)
	{
		return num[i];
	}
};
int main()
{
	int x = 0;
	scanf("%d", &x);
	//
	at a;
	a.in(1);
	int am = 3;
	while (a.c < x)
	{
		for (int i = 1 ; i <= am ; i++)
		{
			a.in(i);
		}
		for (int i = am-1 ; i >= 1 ; i--)
		{
			a.in(i);
		}
		am += 2;
	}
	//
	at b;
	int bm = 2;
	while (b.c < x)
	{
		for (int i = 1 ; i <= bm ; i++)
		{
			b.in(i);
		}
		for (int i = bm-1 ; i >= 1 ; i--)
		{
			b.in(i);
		}
		bm += 2;
	}
	//
	printf("%d/%d", a.get(x), b.get(x));
	return 0;
}
