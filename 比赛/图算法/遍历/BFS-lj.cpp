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
vector<int>b[200];
int dian = 0,bian = 0;
bool go[200] = {0};
int c = 0;
void bfs(int start)
{
	cout << start;
	go[start] = 1;
	queue<int>a;
	a.push(start);
	int now = start;
	c = 1;
	while(c < dian)
	{
		for(int k = a.size() ; k >= 1 ; k--)
		{
			now = a.back();
			a.pop();
			for(int i = 1 ; i <= dian ; i++)
			{
				if((go[i] == 0) && (find(b[now].begin(),b[now].end(),i) != b[now].end()))
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
	cin >> dian >> bian;
	for(int i = 0 ; i < bian ; i++)
	{
		int s = 0,e = 0;
		cin >> s >> e;
		b[s].push_back(e);
		b[e].push_back(s);
	}
	int start = 0;
	bfs(start);
	return 0;
}
