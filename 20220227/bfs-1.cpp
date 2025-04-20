#include<iostream>
#include<conio.h>
#include<cstdio>
#include<cstdlib>
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int m[10][10] = {0,0,1,0,0,1,0,0,0,0,
                 0,0,0,1,0,0,1,0,0,0,
                 0,0,0,1,0,0,1,0,0,0,
                 0,0,0,1,0,1,0,0,0,0,
                 0,0,0,0,1,0,0,0,0,0
                };
int x = 0,y = 0;
void show()
{
	system("cls");
	for(int i = 0 ; i < 10 ; i++)
	{
		for(int j = 0 ; j < 10 ; j++)
		{
			if((i == x) && (j == y))
			{
				if(m[i][j] == 1)
				{
					cout << setw(2) << "¡è";
				}
				else
				{
					cout << setw(2) << "¡ò";
				}
			}
			else if(m[i][j] == 0)
			{
				cout << setw(2) << "¡õ";
			}
			else if(m[i][j] == 1)
			{
				cout << setw(2) << "¡ö";
			}
			else if(m[i][j] == 2)
			{
				cout << setw(2) << "¡Ë";
			}
		}
		cout << endl;
	}
}
void draw(int x,int y)
{
	if((x >= 0) && (x <= 9) && (y >= 0) && (y <= 9) && (m[x][y] == 0))
	{
		Sleep(50);
		show();
		m[x][y] = 2;
		draw(x+1,y);
		draw(x-1,y);
		draw(x,y-1);
		draw(x,y+1);
	}
}
int main()
{
	//cout << "¡÷¨Œ¡ð¡ó¡õ¡î¡ø¨‹¡ñ¡ô¡ö¡ï¡â¡á¨E¡­¨x¨y¨z¨{¨|¨}¨~¨€¡Ë¡ù¨ˆ¨‡¨†¨…¨„¨ƒ¨‚¨¡ì¡ò¡è¡¬…d…e¡þ" << endl;
	while(1)
	{
		show();
		char c = getch();
		if(c == 'w')
		{
			if(x > 0)
			{
				x--;
			}
		}
		else if(c == 's')
		{
			if(x < 9)
			{
				x++;
			}
		}
		else if(c == 'a')
		{
			if(y > 0)
			{
				y--;
			}
		}
		else if(c == 'd')
		{
			if(y < 9)
			{
				y++;
			}
		}
		else if(c == ' ')
		{
			Sleep(500);
			draw(x,y);
		}
	}
	show();
	return 0;
}
