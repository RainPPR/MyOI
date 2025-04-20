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
int main()
{
	int n = 0;
	int k = 0;
	cin >> n >> k;
	int t[10] = {0};
	for (int i = 0 ; i < k ; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		t[a]++;
	}
	int c = 0;
	int j = 0;
	while (n)
	{
		int t2 = n % 10;
		for (int i = 0 ; i < 10 ; i++)
		{
			for (int j = 0 ; j < t[i] ; j++)
			{
				if (t2 == i)
				{
					c++;
				}
			}
			if(t[i] >= 2)
			{
				j += t[i] - 1;
			}
		}
		n /= 10;
	}
	j /= 2;
	int ov = 0;
	for (int i = c ; i >= 1 ; i--)
	{
		ov += i;
	}
	ov += j + 1;
	cout << ov << endl;
	return 0;
}
