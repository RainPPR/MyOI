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
	int money = 0;
	int cun = 0;
	for(int i = 1 ; i <= 12 ; i++)
	{
		//ÔÂ³õ
		int hua = 0;
		cin >> hua;
		money += 300;
		//ÔÂÄ©
		money = money-hua;
		if(money < 0)
		{
			cout << "-" << i << endl;
			return 0;
		}
		else if(money >= 100)
		{
			int tcun = money/100*100;
			cun += tcun;
			money -= tcun;
		}
	}
	money += cun*2/10+cun;
	cout << money << endl;
	return 0;
}
