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
int mi[4] = {-1,0,0,1};
int mj[4] = {0,-1,1,0};
int _m[102][102] = {0};
int n = 0,m = 0;
void tian(int i,int j)
{
	_m[i][j] = -1;
	for(int k = 0 ; k < 4 ; k++)
	{
		int x = i+mi[k];
		int y = j+mj[k];
		if(x >= 1 && y >= 1 && x <= n && y <= m && _m[x][y] >= 1 && _m[x][y] <= 9)
		{
			tian(x,y);
		}
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
	{
		string str;
		cin >> str;
		for(int j = 1 ; j <= m ; j++)
		{
			_m[i][j] = str[j-1]-'0';
		}
	}
	int count = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(_m[i][j] >= 1 && _m[i][j] <= 9)
			{
				tian(i,j);
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
