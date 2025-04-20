#include<iostream>
using namespace std;
int dian = 0,bian = 0;
int mp[100][100] = {0};
bool go[100] = {0};
void dfs(int start)
{
	go[start] = 1;
	for(int i = 1 ; i <= dian ; i++)
	{
		if((go[i] == 0) && (mp[start][i] == 1))
		{
			cout << " -> " << i;
			dfs(i);
			break;
		}
	}
	return;
}
int main()
{
	cin >> dian >> bian;
	for(int i = 1 ; i <= bian ; i++)
	{
		int start = 0,end = 0;
		cin >> start >> end;
		mp[start][end] = 1;
		mp[end][start] = 1;
	}
	int sq = 0;
	cin >> sq;
	cout << sq;
	dfs(sq);
	return 0;
}
