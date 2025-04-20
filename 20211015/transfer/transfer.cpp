#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
struct t
{
	int time = 0;
	int price = 0;
	bool canuse = 0;
} piao[1000000];
int ps = 0;
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	int n = 0;
	cin >> n;
	int hua = 0;
	for(int i = 0 ; i < n ; i++)
	{
		int fangs = 0;
		int price = 0;
		int time = 0;
		cin >> fangs >> price >> time;
		if(fangs == 0)
		{
			piao[ps].time = time;
			piao[ps].price = price;
			piao[ps].canuse = true;
			ps++;
			hua += price;
		}
		else
		{
			bool nuse = true;
			int usej = -1;
			for(int j = 0 ; j < ps ; j++)
			{
				if(piao[j].canuse)
				{
					if(time - piao[j].time <= 45)
					{
						if(price <= piao[j].price)
						{
							nuse = false;
							piao[j].canuse = false;
							usej = j;
							break;
						}
					}
					else
					{
						piao[j].canuse = false;
					}
				}
			}
			if(nuse)
			{
				hua += price;
			}
		}
	}
	cout << hua << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
