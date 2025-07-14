#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int N = 2e5 + 10;

int n, m;
string s, t;

int main()
{
	cin >> n >> m >> s >> t;

	for (int i = 0 ; i < s.size() && i < t.size() ; ++i)
	{
		if (s[i] != t[i])
		{
			s = s.substr(i, s.size()), t = t.substr(i, t.size());
			break;
		}
	}

	if (s == t || s == t + "*")
		cout << "YES" << endl;
	else
	{
		int cnt = 0;
		for (auto i = s.rbegin(), j = t.rbegin() ; i != s.rend() && j != s.rend() ; ++i, ++j)
			if (*i != *j)
				break;
			else
				++cnt;

		if ((s[0] == '*') && (s.size() - cnt == 1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
