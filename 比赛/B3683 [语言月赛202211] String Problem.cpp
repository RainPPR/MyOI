#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

inline void opt(bool Yn)
{
	if (Yn)
		putchar('Y'), putchar('e'), putchar('s');
	else
		putchar('N'), putchar('o');
	putchar('\n');
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	char c;
	int T, n, q, o, p;

	cin >> T;
	string str[2];
	while (T--)
	{
		cin >> n >> q;
		cin >> str[0] >> str[1];
		opt(str[0] == str[1]);
		while (q--)
		{
			scanf("%d %d %c", &o, &p, &c);
			str[o][p - 1] = c;
			opt(str[0] == str[1]);
		}
	}
	return 0;
}
