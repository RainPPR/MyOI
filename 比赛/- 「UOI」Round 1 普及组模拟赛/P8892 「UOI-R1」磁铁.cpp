#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_set>

using namespace std;

int tong[256];

void opt(bool isOK)
{
	if (isOK)
		putchar('Y');
	else
		putchar('N');
	putchar('\n');
}

bool check(const string &str, const string &target)
{
	string temp = str + str;

	int len = temp.size() - target.size() + 1;
	for (int i = 0 ; i < len ; ++i)
	{
		bool flag = true;
		for (int j = 0 ; j < target.size() ; ++j)
		{
			if (temp[i + j] != target[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			return true;
	}

	return false;
}

bool dfs(string &str, string now, int k, const string &target)
{
	if (now.size() == target.size())
	{
		if (check(now, target))
			return true;
		return false;
	}

	for (int i = k ; i < str.size() ; ++i)
		if (tong[(int)str[i]])
			if (dfs(str, now + str[i], i + 1, target))
				return true;

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		string a, b;
		cin >> a >> b;

		if (a.size() < b.size())
			opt(0);
		else if (a.size() == 1)
		{
			if (b.size() == 1)
			{
				if (a == b)
					opt(1);
				else
					opt(0);
			}
			else
				opt(0);
		}
		else if (b.size() == 1)
		{
			bool flag = false;
			for (char i : a)
			{
				if (i == b[0])
				{
					flag = true;
					break;
				}
			}
			opt(flag);
		}
		else
		{
			memset(tong, 0, sizeof(tong));
			for (char i : b)
				++tong[(int)i];

			opt(dfs(a, "", 0, b));
		}
	}
	return 0;
}
