#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<ctime>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long LL;
const int MR = 4.5e6 + 10;
int n, m, a[MR];
map<int, int> mymap;
int mex()
{
	map<int, int>::iterator it = mymap.begin();
	if (it->first > 0) return 0;
	for (it = mymap.begin(); it != mymap.end(); ++it)
	{
		map<int, int>::iterator nextit = it;
		++nextit;
		if (nextit != mymap.end() && (it->first) + 1 < (nextit->first))
		{
			return (it->first) + 1;
		}
	}
	return (int)mymap.size();
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		mymap[a[i]]++;
	}
	int ans = mex();
	for (int i = m + 1; i <= n; i++)
	{
		mymap[a[i]]++;
		mymap[a[i - m]]--;
		if (mymap[a[i - m]] == 0)
		{
			mymap.erase(a[i - m]);
		}
		ans = min(mex(), ans);
	}
	printf("%d\n", ans);
	return 0;
}
