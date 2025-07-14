#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string str;
int sum1, sum2;

bool dfs(int l, int r)
{
	if (l == r)
		return str[l] - '0';

	int k = 0, posor = 0, posand = 0;
	for (int i = l ; i <= r ; ++i)
	{
		if (str[i] == '(')
			++k;
		else if (str[i] == ')')
			--k;
		else if (!k)
		{
			if (str[i] == '|')
				posor = i;
			else if (str[i] == '&')
				posand = i;
		}
	}

	if (posor)
	{
		bool value1 = dfs(l, posor - 1);
		if (value1 == 1)
		{
			++sum2;
			return 1;
		}
		else
		{
			bool value2 = dfs(posor + 1, r);
			return (value1 | value2);
		}
	}
	if (posand)
	{
		bool value1 = dfs(l, posand - 1);
		if (value1 == 0)
		{
			++sum1;
			return 0;
		}
		else
		{
			bool value2 = dfs(posand + 1, r);
			return (value1 & value2);
		}
	}

	return dfs(l + 1, r - 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> str;

	int ans = dfs(0, str.size() - 1);
	printf("%d\n%d %d\n", ans, sum1, sum2);
	return 0;
}
