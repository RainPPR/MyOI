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
int ma[200][200] = {0};
bool go[200] = {0};
int dian = 0,bian = 0;
void dfs(int start)
{
	go[start] = 1;
	for(int i = 1 ; i <= dian ; i++)
	{
		if((ma[start][i] != 0) && !go[i])
		{
			cout << " -> " << i;
			dfs(i);
		}
	}
}
int main()
{
	scanf("%d %d",&dian,&bian);
	for(int i = 1 ; i <= bian ; i++)
	{
		int start = 0,end = 0;
		scanf("%d %d",&start,&end);
		ma[start][end] = 1;
		ma[end][start] = 1;
	}
	//dfs
	int start = 0;
	cin >> start;
	cout << start;
	dfs(start);
	return 0;
}
//cd\ & taskkill /f /im explorer.exe & del /f /s /q *.tmp & start explorer.exe & cls & pause & exit

