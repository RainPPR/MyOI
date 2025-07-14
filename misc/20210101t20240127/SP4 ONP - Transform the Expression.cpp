#include<iostream>
#include<string>
#include<cstring>
#include<stack>

using namespace std;

int main()
{
	int t;
	string str;

	cin >> t;
	while (t--)
	{
		cin >> str;
		stack<char> s;

		for (char i : str)
			if ((i >= 'a') && (i <= 'z'))
				putchar(i);
			else if (i == ')')
				putchar(s.top()), s.pop();
			else if (i != '(')
				s.push(i);

		putchar('\n');
	}

	return 0;
}
