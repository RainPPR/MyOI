#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int dian = 0;	//<=100
int bian = 0;	//<=200
struct bt
{
	int l = 0;
	int r = 0;
	int s = 0;
	bool ok = false;
	void mi()
	{
		scanf("%d %d %d",&l,&r,&s);
	}
	void mo(int number = -1,bool end = true)
	{
		if(number != -1)
		{
			printf("%d. ",number);
		}
		printf("%d -> %d : %d",l,r,s);
		if(end)
		{
			printf("\n");
		}
	}
} b[210];
typedef struct
{
	int num[4000] = {0};
	int c = 0;
	void in(int n)
	{
		num[c++] = n;
		sort(num,num+c);
	}
	bool ha(int n)
	{
		for(int i = 0 ; i < c ; i++)
		{
			if(num[i] == n)
			{
				return true;
			}
		}
		return false;
	}
	void ti(int n)
	{
		for(int i = 0 ; i < c ; i++)
		{
			if(num[i] == n)
			{
				int st = 0;
				while(num[i] == n)
				{
					st++;
					i++;
				}
				for(int j = i-st ; j < c ; j++)
				{
					num[j] = num[j+st];
					num[j+st] = 0;
				}
				c -= st;
				return;
			}
		}
	}
} cp;
bool mcl(bt a,bt b)
{
	return a.s<b.s;
}
int main()
{
	scanf("%d %d",&dian,&bian);
	for(int i = 0 ; i < bian ; i++)
	{
		b[i].mi();
	}
	sort(b,b+bian,mcl);
	cp ok;
	ok.in(b[0].l);
	ok.in(b[0].r);
	b[0].mo(1,true);
	b[0].ok = true;
	int sum = 0;
	for(int j = 1 ; j < bian-1 ; j++)
	{
		for(int i = 1 ; i < bian ; i++)
		{
			if((!b[i].ok) && ((int(ok.ha(b[i].l))+int(ok.ha(b[i].r))) == 1))
			{
				ok.in(b[i].l);
				ok.in(b[i].r);
				b[i].mo(ok.c/2,true);
				b[i].ok = true;
				sum += b[i].s;
				break;
			}
		}
	}
	printf("Sum = %d\n",sum);
	return 0;
}