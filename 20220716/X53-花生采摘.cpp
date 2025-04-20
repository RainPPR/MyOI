#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef struct
{
	int x = 0;
	int y = 0;
	int n = -1;
} nt;
nt add(int x, int y, int n)
{
	nt a;
	a.x = x,
	a.y = y;
	a.n = n;
	return a;
}
bool compare(nt a, nt b)
{
	return a.n > b.n;
}
int main()
{
	int m = 0, n = 0, k = 0;
	scanf("%d %d %d", &m, &n, &k);
	vector<nt>map;
	map.push_back(add(0, 0, 0));
	for (int i = 1 ; i <= m ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
		{
			int num = 0;
			scanf("%d", &num);
			if (num > 0)
			{
				map.push_back(add(i, j, num));
			}
		}
	}
	//
	sort(map.begin() + 1, map.end(), compare);
	//
	int need[500] = {0};
	int sum = 0;
	int ans = 0;
	for (int i = 1 ; i < map.size() ; i++)
	{
		int point = 0;
		if (i == 1)
		{
			point = map[1].x + 1;
		}
		else
		{
			point = min((abs(map[i].x - map[i - 1].x) + abs(map[i].y - map[i - 1].y)), (map[i].x + map[i - 1].x)) + 1;
		}
		need[i] = point + need[i - 1] + map[i].y - map[i - 1].y;
		sum += map[i].n;
		if (need[i] <= k)
		{
			ans = max(ans, sum);
		}
		else
		{
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
