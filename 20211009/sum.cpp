#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int n = 0,m = 0;
struct t
{
	int number = 0;
	int color = 0;
	int no = 0;
}p[1000001];
int main()
{
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> p[i].number;
		p[i].no = i;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> p[i].color;
	}
	//
	int fen = 0;
	for(int x = 1 ; x <= n-2 ; x++)
	{
		for(int y = x+1 ; y <= n-1 ; y++)
		{
			int z = y-x+y;
			if((p[x].color == p[y].color) && (p[x].color == p[z].color) && (p[y].color == p[z].color))
			{
				cout << x << " " << y << " " << z << endl; 
				int fent = (x+z)*(p[x].number+p[z].number);
				fen = (fen+fent)/*%10007*/;
			}
		}
	}
	cout << fen << endl;
//	fclose(stdin);
//	fclose(stdout);
}
