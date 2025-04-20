#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	int n = 0;
	cin >> n;
	string m;
	cin >> m;
	string str;
	string sss;
	for(int i = 0 ; i < 60 ; i++)
	{
		char c = 0;
		cin >> c;
		str += +c;
		sss+=m[i%n];
	}
	int money = 10;
	for(int i = 0 ; i < 60 ; i++)
	{
		if(sss[i] == str[i])
		{
			money++;
		}
		else
		{
			money--;
		}
		if(money <= 0)
		{
			cout << "bank." << endl;
			return 0;
		}
	}
	cout << money-10 << endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
