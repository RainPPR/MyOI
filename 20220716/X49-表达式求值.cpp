#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	string str, now;
	cin >> str;
	str += '#';
	ll sum = 0;
	for (int i = 0 ; i < str.size() ; i++)
	{
		if (str[i] == '+' || str[i] == '#')
		{
			ll ans = 1;
			ll temp = 0;
			for (int j = 0 ; j < now.size() ; j++)
			{
				if (ans == 0)
				{
					break;
				}
				else if (now[j] == '*')
				{
					ans = (ans * (temp % 10000)) % 10000;
					temp = 0;
				}
				else
				{
					temp = temp * 10 + now[j] - '0';
				}
			}
			ans = (ans * (temp % 10000)) % 10000;
			sum = (sum + (ans % 10000)) % 10000;
			now = "";
		}
		else
		{
			now += str[i];
		}
	}
	cout << sum << endl;
	return 0;
}
