#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin >> str;
	int count = 0;
	for(int i = 0 ; i < str.size() ; i++)
	{
		if(str[i] == '1')
		{
			count++;
		}
	}
	cout << count << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
