#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<string.h>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	ll n = 0;
	ll m = 0;
	string bin;
	string code;
	cin >> n >> m;
	cin >> bin;
	bin = bin;
	cin >> code;
	for (int i = 0 ; i < code.size() ; i++)
	{
		switch (code[i])
		{
			case '*':
			{
				bin.push_back('0');
				break;
			}
			case '/':
			{
				bin.pop_back();
				break;
			}
			case '+':
			{
				for (int j = bin.size() - 1 ; j >= 0 ; j--)
				{
					if (bin[j] == '0')
					{
						bin[j] = '1';
						break;
					}
					else
					{
						bin[j] = '0';
					}
				}
				break;
			}
			case '-':
			{
				for (int j = bin.size() - 1 ; j >= 0 ; j--)
				{
					if (bin[j] == '1')
					{
						bin[j] = '0';
						break;
					}
					else
					{
						bin[j] = '1';
					}
				}
				break;
			}
		}
	}
	cout << bin << endl;
	return 0;
}
