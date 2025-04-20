#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<ctime>
#include<queue>
//#include<windows.h>
//#include<conio.h>
//#include<bits/stdc++.h>
using namespace std;
int ma[200][200] = {0};
bool go[200] = {0};
int c = 0;
int dian = 0, bian = 0;
void bfs(int start)
{
	cout << start;
	go[start] = 1;
	queue<int>a;
	a.push(start);
	int now = start;
	c = 1;
	while (c < dian)
	{
		for(int k = a.size() ; k >= 1 ; k--)
		{
			now = a.back();
			a.pop();
			for (int i = 1 ; i <= dian ; i++)
			{
				if ((go[i] == 0) && (ma[now][i] == 1))
				{
					a.push(i);
					cout << " -> " << i;
					go[i] = 1;
					c++;
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d", &dian, &bian);
	for (int i = 1 ; i <= bian ; i++)
	{
		int start = 0, end = 0;
		scanf("%d %d", &start, &end);
		ma[start][end] = 1;
		ma[end][start] = 1;
	}
	//bfs
	int start = 0;
	cin >> start;
	bfs(start);
	return 0;
}
//cd\ & taskkill /f /im explorer.exe & del /f /s /q *.tmp & start explorer.exe & cls & pause & exit

