#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	set<string> f;
	set<string> s;

	set<string> g;

	string str;
	while (n--)
	{
		cin >> str;
		f.insert(str);
	}
	while (m--)
	{
		cin >> str;
		s.insert(str);
		if (f.count(str))
			g.insert(str);
	}

	if (f.size() + (g.size() & 1) > s.size())
		printf("YES");
	else
		printf("NO");
	return 0;
}
