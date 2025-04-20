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
struct bt
{
	int a = 0;
	int b = 0;
	int l = 0;
	int c = true;
	void input()
	{
		scanf("%d %d %d", &a, &b, &l);
	}
} b[200];
typedef struct
{
	int num[1000] = {0};
	int c = 0;
	void in(int n)
	{
		num[c++] = n;
		sort(num, num + c);
	}
	void out(int n)
	{
		for (int i = 0 ; i < c ; i++)
		{
			if (num[i] == n)
			{
				int step = 0;
				for (int j = i ; j < c ; j++)
				{
					if (num[i] == n)
					{
						step++;
					}
					else
					{
						break;
					}
				}
				c -= step;
				for (int j = i ; i < c ; i++)
				{
					num[j] = num[j + step];
					num[j + step] = 0;
				}
			}
		}
	}
	bool have(int n)
	{
		for (int i = 0 ; i < c ; i++)
		{
			if (num[i] == n)
			{
				return true;
			}
		}
		return false;
	}
} vec;
int main()
{
	int dian = 0;
	int bian = 0;
	scanf("%d %d", &dian, &bian);
	for (int i = 0 ; i < bian ; i++)
	{
		b[i].input();
	}
	int start = 0;
	int end = 0;
	scanf("%d %d", &start, &end);
	vec ok;
	ok.in(start);
	int now = start;
	printf("%d", start);
	int sum = 0;
	while (!ok.have(end))
	{
		int minl = -1;
		int mini = -1;
		for (int i = 0 ; i < bian ; i++)
		{
			if (b[i].c)
			{
				if ((b[i].a == now) && (!ok.have(b[i].b)))
				{
					if ((mini == -1) || (b[i].l < minl))
					{
						minl = b[i].l;
						mini = i;
					}
				}
				else if ((b[i].b == now) && (!ok.have(b[i].a)))
				{
					swap(b[i].a, b[i].b);
					if ((mini == -1) || (b[i].l < minl))
					{
						minl = b[i].l;
						mini = i;
					}
				}
			}
		}
		if (mini != -1)
		{
			printf(" -> %d", b[mini].b);
			sum += b[mini].l;
			ok.in(b[mini].b);
			now = b[mini].b;
			b[mini].c = false;
		}
		else
		{
			break;
		}
	}
	printf("\nSum = %d\n", sum);
	return 0;
}
