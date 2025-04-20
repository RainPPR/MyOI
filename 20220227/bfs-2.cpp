#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
vector<int>a[100];
int go[200] = {0};
void dfs(int s)
{
	go[s] = 1;
	for(int i = 0 ; i < a[s].size() ; i++)
	{
		if(!go[a[s][i]])
		{
			cout << " -> " << a[s][i];
			dfs(a[s][i]);
		}
	}
}
typedef struct
{
	int xuhao = 0;
	bool youxiao = false;
} yuansu;
vector<yuansu>que;
int cq = 0;
void bfs(int s)
{
	go[s] = 1;
	yuansu y;
	y.xuhao = s;
	y.youxiao = true;
	que.push_back(y);
	cq++;
	while(cq > 0)
	{
		int yxuhao = 0;
	}
}
int main()
{
	try
	{
		system("title %windir%\\system32\\cmd.exe");
		system("cmd -v");
		int dian = 0,bian = 0;
		cin >> dian >> bian;
		for(int i = 0 ; i < bian ; i++)
		{
			int start = 0,end = 0;
			cin >> start >> end;
			a[start].push_back(end);
			a[end].push_back(start);
		}
		//out
		cout << "--------------------" << endl;
		for(int i = 0 ; i < dian ; i++)
		{
			cout << i << "[";
			for(int j = 0 ; j < a[i].size() ; j++)
			{
				cout << " -> " << a[i][j];
			}
			cout << endl;
		}
		//dfs
		cout << "--------------------" << endl;
		int start = 0;
		cin >> start;
		cout << start;
		dfs(start);
		cout << endl;
		//bfs
		cout << "--------------------" << endl;
		bfs(start);
		return 0;
	};
	return 1;
}
