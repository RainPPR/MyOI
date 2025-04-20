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
string sget(string &str)
{
	str = "";
	while (1)
	{
		string st;
		cin >> st;
		str += st;
		if (str[str.size() - 1] == 'E')
		{
			break;
		}
	}
	str.pop_back();
	return str;
}
int main()
{
	string str;
	sget(str);
	if(str == "")
	{
		printf("0:0\n\n0:0\n");
		return 0;
	}
	//11·ÖÖÆ
	int e_w = 0;
	int tc = 0;
	int t_w[5682] = {0};
	int fend = -1;
	for (int i = 0 ; i < str.size() ; i++)
	{
		if (str[i] == 'W')
		{
			e_w++;
			t_w[tc]++;
		}
		if (((i + 1) % 11 == 0))
		{
			printf("%d:%d\n", e_w, 11 - e_w);
			e_w = 0;
			if (i == str.size() - 1)
			{
				printf("0:0\n");
			}
		}
		else if (i == str.size() - 1)
		{
			int e_l = (i + 1) % 11 - e_w;
			printf("%d:%d\n", e_w, e_l);
		}
		if (((i + 1) % 21 == 0))
		{
			tc++;
		}
		else if (i == str.size() - 1)
		{
			fend = i + 1;
			tc++;
		}
	}
	printf("\n");
	for (int i = 0 ; i < tc ; i++)
	{
		if ((fend != -1) && (i == tc - 1))
		{
			int t_l = fend % 21 - t_w[i];
			printf("%d:%d\n", t_w[i], t_l);
		}
		else
		{
			printf("%d:%d\n", t_w[i], 21 - t_w[i]);
			if(i == tc -1)
			{
				printf("0:0\n");
			}
		}
	}
	return 0;
}
