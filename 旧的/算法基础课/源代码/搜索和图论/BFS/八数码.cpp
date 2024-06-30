#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
vector<int> getpos(int z)
{
	vector<int> pos;
	if (z > 2)
		pos.push_back(z - 3);
	if (z % 3 != 0)
		pos.push_back(z - 1);
	if (z % 3 != 2)
		pos.push_back(z + 1);
	if (z < 6)
		pos.push_back(z + 3);
	return pos;
}
int bfs(string start)
{
	string end = "12345678x";

	queue<string> q;
	unordered_map<string, int>d;

	q.push(start);
	d[start] = 0;

	while (!q.empty())
	{
		string t = q.front();
		q.pop();

		int dis = d[t];

		if (t == end)
			return dis;

		int k = t.find('x');
		auto pos = getpos(k);
		for (int i = 0 ; i < pos.size() ; ++i)
		{
			swap(t[k], t[pos[i]]);
			if (!d.count(t))
			{
				d[t] = dis + 1;
				q.push(t);
			}
			swap(t[k], t[pos[i]]);
		}
	}
	return -1;
}
int main()
{
	string str;
	for (int i = 0 ; i < 9 ; ++i)
	{
		char c = getc(stdin);
		getc(stdin);
		str += c;
	}
	printf("%d", bfs(str));
	return 0;
}
