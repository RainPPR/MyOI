#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	string ans;

	string now;
	for (int i = 0 ; i < str.size() ; ++i)
	{
		if (str[i] == '@')
		{
			if (i == str.size() - 1)
			{
				printf("No solution\n");
				return 0;
			}
			else if (now.size() && (str[i + 1] != '@'))
			{
				ans += ",";
				ans += now;
				ans += "@";
				ans += str[++i];
				now = "";
			}
			else
			{
				printf("No solution\n");
				return 0;
			}
		}
		else
			now += str[i];
	}

	if (!ans.size())
	{
		printf("No solution\n");
		return 0;
	}
	ans += now;
	ans = ans.substr(1, ans.size()).c_str();

	cout << (ans.size() ? ans.c_str() : "No solution") << endl;
	return 0;
}
