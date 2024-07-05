#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1000005;
int n, sz[N], v[N], l[N], r[N];
void dfs(int x)
{
	sz[x] = 1;
	if(l[x] > 0){
		dfs(l[x]);
		sz[x] += sz[l[x]];
	}
	if(r[x] > 0){
		dfs(r[x]);
		sz[x] += sz[r[x]];
	}
}
bool check(int x, int y) //检查x的子树是否与y的子树对称 
{
	if(x == -1 && y == -1) return true;
	if(x == -1 || y == -1 || v[x] != v[y]) return false;
	if(check(l[x], r[y]) && check(r[x], l[y]))
		return true;
	return false;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &l[i], &r[i]);
	dfs(1);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(check(l[i], r[i]))
			ans = max(ans, sz[i]);
	printf("%d\n", ans);
	return 0;
}
