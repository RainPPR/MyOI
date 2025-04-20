#include<iostream>
using namespace std;
struct ge
{
	bool iscolor = false;
	int color = -1; //0-red 1-yellow 2-red or yellow
	bool ismagic = false;
	int money = 0;
} mp[101][101];
int book[101][101] = {0};
int x, y, c;
int main()
{
	int m = 0, n = 0;
	scanf("%d %d", &m, &n);
	for (int i = 0 ; i < n ; i++)
	{
		scanf("%d %d %d", &x, &y, &c);
		mp[x][y].iscolor = true;
		mp[x][y].color = c;
	}
	for (int i = 1 ; i <= m ; i++)
	{
		for (int j = 1 ; j <= m ; j++)
		{
			//从上方来
			ge now1 = mp[i][j];
			if (i != 1)
			{
				if ((now1.iscolor == false) && (mp[i - 1][j].ismagic == false) && (mp[i - 1][j].color != -1))
				{
					now1.ismagic = true;
					now1.iscolor = true;
					now1.color = mp[i - 1][j].color;
					now1.money += 2;
				}
				else if ((now1.color != mp[i - 1][j].color) && (mp[i - 1][j].color != 2))
				{
					now1.money += 1;
				}
			}
			//从左侧来
			ge now2 = mp[i][j];
			if (j != 1)
			{
				if ((now2.iscolor == false) && (mp[i][j - 1].ismagic == false) && (mp[i][j - 1].color != -1))
				{
					now2.ismagic = true;
					now2.iscolor = true;
					now2.color = mp[i][j - 1].color;
					now2.money += 2;
				}
				else if ((now2.color != mp[i][j - 1].color) && (mp[i][j - 1].color != 2))
				{
					now2.money += 1;
				}
			}
			//
			if (now1.money < now2.money)
			{
				mp[i][j] = now1;
			}
			else if (now2.money < now1.money)
			{
				mp[i][j] = now2;
			}
			else
			{
				now1.color = 3;
				mp[i][j] = now1;
			}
		}
	}
	cout << mp[m][m].money;
	return 0;
}
