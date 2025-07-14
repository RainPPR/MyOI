#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <cstring>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	unordered_set<int> ans;

	int x;
	for (int j = 0 ; j < m ; ++j)
	{
		scanf("%d", &x);
		ans.emplace(x);
	}
	for (int i = 1 ; i < n ; ++i)
	{
		unordered_set<int> now = ans;
		for (int j = 0 ; j < m ; ++j)
		{
			scanf("%d", &x);
			for (int k : now)
				ans.emplace(k ^ x);
		}
	}

	if (ans.count(0))
		printf("Found\n");
	else
		printf("Nothing\n");
	return 0;
}
