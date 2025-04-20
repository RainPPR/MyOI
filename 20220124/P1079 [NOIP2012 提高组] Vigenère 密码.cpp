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
char ov[30][30];
char upper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 'a' - 'A';
	}
	if (c >= 'A' && c <= 'Z')
	{
		return c;
	}
	else
	{
		return 0;
	}
}
char getmi(char ming, char key)
{
	char c = ov[upper(key)-'A'][upper(ming)-'A'];
	if(ming >= 'a' && ming <= 'z')
	{
		c += 'a'-'A';
	}
	return c;
}
char getming(char mi,char key)
{
	char t = 'a';
	for(int i = 0 ; i < 26 ; i++)
	{
		char ming = t+i;
		char mt = getmi(ming,key);
		if(mt == mi)
		{
			return ming;
		}
		mt = getmi(upper(ming),key);
		if(mt == mi)
		{
			return upper(ming);
		}
	}
}
int main()
{
	for (int i = 0 ; i < 26 ; i++)
	{
		for (int j = 0 ; j < 26 ; j++)
		{
			ov[i][j] = (i + j) % 26 + 'A';
		}
	}
	string key;
	string mi;
	cin >> key;
	cin >> mi;
	while(key.size() < mi.size())
	{
		key = key+key;
	}
	//
	for(int i = 0 ; i < mi.size() ; i++)
	{
		cout << char(getming(mi[i],key[i]));
	}
	return 0;
}
