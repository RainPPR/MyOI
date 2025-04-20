#include<iostream>
using namespace std;
int main()
{
	int hx[256] = {0};
	string str;
	cin >> str;
	for (int i = 0 ; i < str.size() ; i++)
	{
		hx[str[i]]++;
	}
	int qi = 0;
	for (int i = 0 ; i < str.size() ; i++)
	{
		if ((hx[str[i]] & 1) != 0)
		{
			qi++;
		}
		//
		if (qi > 1)
		{
			cout << "false" << endl;
			return 0;
		}
	}
	cout << "true" << endl;
	return 0;
}
