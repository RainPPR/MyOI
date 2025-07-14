#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 1010;

void opt(bool isOK)
{
	if (isOK)
		putchar('Y');
	else
		putchar('N');
	putchar('\n');
}

bool isSub(string a, string b)
{
	int i = 0, j = 0;
	while ((i < a.size()) && (j < b.size()))
	{
		if (a[i] == b[j])
			++j;
		++i;
	}
	return j == b.size();
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

		int len = a.size();
		a = a + a;

		bool flag = false;
		for (int i = 0 ; i < len ; ++i)
		{
			string c = a.substr(i, len);
			if (isSub(c, b))
			{
				flag = true;
				break;
			}
		}

		opt(flag);
	}
	return 0;
}
