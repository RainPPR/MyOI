#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int md[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
struct date
{
	int year = 0;
	int month = 0;
	int day = 0;
};
int gethe(date a)
{
	int z = a.day+a.month*100+a.year*10000;
	return z;
}
bool huiwen(date a)
{
	int z = gethe(a);
	int z1 = z;
	int z2 = 0;
	while(z)
	{
		z2 = z2*10+z%10;
		z /= 10;
	}
	if(z1 == z2)
	{
		return true;
	}
	return false;
}
bool runn(date a)
{
	int z = gethe(a);
	if(((z % 4 == 0) && (z % 100 != 0)) || (z % 400 == 0))
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	date start;
	date end;
	scanf("%4d%2d%2d",&start.year,&start.month,&start.day);
	scanf("%4d%2d%2d",&end.year,&end.month,&end.day);
	if(gethe(start) == gethe(end))
	{
		if(huiwen(start))
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
		return 0;
	}
	int count = 0;
	do
	{
		if(huiwen(start))
		{
			count++;
		}
		start.day++;
		if(runn(start))
		{
			md[2] = 29;
		}
		else
		{
			md[2] = 28;
		}
		if(start.day > md[start.month])
		{
			start.day = 1;
			start.month++;
		}
		if(start.month > 12)
		{
			start.month = 1;
			start.year++;
		}
	} while(gethe(start) != gethe(end));
	if(huiwen(start))
	{
		cout << gethe(start) << endl;
		count++;
	}
	cout << count << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
