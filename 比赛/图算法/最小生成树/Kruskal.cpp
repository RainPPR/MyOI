/*
6 10
1 2 1
1 3 2
2 3 3
2 4 9
2 5 19
3 4 12
3 5 17
4 6 4
4 5 8
5 6 7
*/
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
typedef struct
{
	int num[1000];
	int c = 0;
	void insert(int n)
	{
		num[++c] = n;
		sort(num + 1, num + 1 + c, less<int>());
	}
	void erase(int n)
	{
		bool bre = false;
		int i = -1;
		int weishu = 0;
		for (int j = 1 ; j <= c ; j++)
		{
			if (num[j] == n)
			{
				if (!bre)
				{
					i = j;
				}
				weishu++;
				bre = true;
			}
			else if (bre)
			{
				break;
			}
		}
		for (int j = i + weishu ; j <= c ; j++)
		{
			num[j - weishu] = num[j];
			num[j] = 0;
		}
		c = c - weishu;
	}
	void output(bool isn = true)
	{
		for (int i = 1 ; i <= c ; i++)
		{
			cout << num[i] << " ";
		}
		if (isn)
		{
			cout << endl;
		}
	}
	bool ishave(int n)
	{
		for (int i = 1 ; i <= c; i++)
		{
			if (num[i] == n)
			{
				return true;
			}
		}
		return false;
	}
} list;
list ok;
int dian = 0;
int bian = 0;
struct bt
{
	int s = 0;
	int e = 0;
	int l = 0;
	void input()
	{
		cin >> s >> e >> l;
	}
	void output()
	{
		cout << min(s, e) << " -> " << max(s, e) << " : " << l << endl;
	}
} b[200];
bool mycompare(bt a, bt b)
{
	return a.l < b.l;
}
int main()
{
	cin >> dian >> bian;
	for (int i = 1 ; i <= bian ; i++)
	{
		b[i].input();
	}
	sort(b + 1, b + 1 + bian, mycompare);
	//
	int length_sum = b[1].l;
	ok.insert(b[1].s);
	ok.insert(b[1].e);
	b[1].output();
	while (1)
	{
		bool isb = true;
		for (int i = 2 ; i <= bian ; i++)
		{
			int na = !ok.ishave(b[i].s);
			int nb = !ok.ishave(b[i].e);
			//if (na || nb)
			if ((!na && nb) || (!nb && na))
			{
				b[i].output();
				ok.insert(b[i].s);
				ok.insert(b[i].e);
				length_sum += b[i].l;
				isb = false;
				break;
			}
		}
		if (isb)
		{
			break;
		}
	}
	cout << "Sum: " << length_sum << endl;
	return 0;
}

