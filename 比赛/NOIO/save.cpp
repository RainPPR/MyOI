#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<ctime>
//#include<windows.h>
//#include<conio.h>
//#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	int t = 0;
	cin >> t;
	string mname;
	int mcount = 0;
	bool first = true;
	while(t--)
	{
		string name;
		cin >> name;
		string str;
		cin >> str;
		int count = 0;
		for(int i = 1 ; i < str.size()-1 ; i++)
		{
			if((str[i-1] == 's') && (str[i] == 'o') && (str[i+1] == 's'))
			{
				count++;
			}
		}
		if(count > mcount)
		{
			mcount = count;
			mname = name;
		}
		else if (count == mcount)
		{
			if(mname != "")
			{
				mname += " ";
			}
			mname += name;
		}
	}
	cout << mname << endl << mcount << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
