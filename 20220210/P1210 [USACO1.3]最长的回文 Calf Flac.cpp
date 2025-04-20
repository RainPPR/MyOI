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
//#include<bits/stdc++.h>
//#include<windows.h>
//#include<conio.h>
using namespace std;
string get(string &ss, string &sf)
{
	string str;
	cin >> str;
	cin >> str;
	cin.get();
	getline(cin, str);
	for (int i = 0 ; i < str.size() ; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			ss += str[i] - 'A' + 'a';
			sf += str[i];
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			ss += str[i];
			sf += str[i];
		}
	}
	return str;
}
int main()
{
	string ss;
	string sf;
	string str = get(ss, sf);
	for(int s = 0 ; s < ss.size() ; s++)
	{
		for(int e = s+1 ; e < ss.size() ; e++)
		{
			
		}
	}
	return 0;
}
