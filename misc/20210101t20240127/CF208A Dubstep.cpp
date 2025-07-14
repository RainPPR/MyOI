#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.size() ; i += 3)
	{
		if (str.substr(i, 3) == "WUB")
			continue;
		str = str.substr(i, str.size());
		break;
	}

	bool flag = true;
	for (int i = 0; i < str.size() ; ++i)
	{
		if (str.substr(i, 3) == "WUB")
		{
			if (flag)
				putchar(' ');
			flag ^= 1;

			i += 2;
			continue;
		}
		putchar(str[i]);
		flag = true;
	}
	putchar('\n');

	return 0;
}
