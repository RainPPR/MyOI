#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<ctime>
#include<map>
//#include<windows.h>
//#include<conio.h>
//#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0;
	bool flag = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			flag = 0;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return (flag ? x : ~(x - 1));
}
int main()
{
	int n = read();
	map<int, int>si;
	int x = 0,t = 0;
	unsigned long long sum = 0;
	for (int i = 0 ; i < n ; i++)
	{
		x = read();
		t = read();
		if ((t > 1) && (si[x] == NULL))
		{
			si[x] = t;
			sum += si[x];
		}
	}
	cout << sum;
	return 0;
}
