#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int n = 0;
int num[10001] = {0};
int a[10001] = {0};
int nn = 0;
bool jin[10001] = {0};
void dfs(int m,int end)
{
	if(m == end+1)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			cout << num[i] << " ";
		}
		cout << endl;
		return;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(!jin[i])
		{
			num[++nn] = a[i];
			jin[i] = 1;
			dfs(m+1,end);
			num[nn--] = 0;
			jin[i] = 0;
		}
	}
}
int main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	dfs(1,n);
	return 0;
}
