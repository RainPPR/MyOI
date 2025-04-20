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
	freopen("pencil.in","r",stdin);
	freopen("pencil.out","w",stdout);
	int n = 0;
	cin >> n;
	int minqian = -1;
	for(int i = 0 ; i < 3 ; i++)
	{
		int shu = 0,jia = 0;
		cin >> shu >> jia;
		int mai = n/shu;
		if(n%shu!=0)
		{
			mai++;
		}
		int qian = mai*jia;
		if((i == 0) || (qian < minqian))
		{
			minqian = qian;
		}
	}
	cout << minqian << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
