#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<ctime>
//#include<windows.h>
//#include<conio.h>
//#include<bits/stdc++.h>
using namespace std;
typedef struct
{
	unsigned short number[20] = {0};
	int length = 0;
	void input()
	{
		char c = getc(stdin);
		if (c == 10)
		{
			c = 0;
		}
		int i = 0;
		while (1)
		{
			if (c == 0)
			{
				c = getc(stdin);
			}
			if ((c > '0') && (c < '9'))
			{
				number[i++] = c - '0';
			}
			else if (c == 10)
			{
				break;
			}
			else
			{
				c = getc(stdin);
			}
			c = 0;
		}
		length = i;
	}
	void output(bool en = true)
	{
		for (int i = 0 ; i < length ; i++)
		{
			printf("%1d", number[i]);
		}
		if (en)
		{
			printf("\n");
		}
	}
} gnum;
bool comp(gnum a, gnum b)
{
	for (int i = 0 ; i < max(a.length, b.length) ; i++)
	{
		if (i == a.length - 1)
		{
			return true;
		}
		if (i == b.length - 1)
		{
			return false;
		}
		if (a.number[i] > b.number[i])
		{
			return true;
		}
		else if (a.number[i] < b.number[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	gnum numlist[1001];
	for (int i = 0 ; i < n ; i++)
	{
		numlist[i].input();
	}
	sort(numlist, numlist + n, comp);
	for (int i = 0 ; i < n ; i++)
	{
		numlist[i].output(0);
	}
	printf("\n");
	return 0;
}
