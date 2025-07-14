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
int dian = 0;
int bian = 0;
int mmap[100][100] = {0};
int main()
{
	for (int i = 0 ; i < 100 ; i++)
	{
		for (int j = 0 ; j < 100 ; j++)
		{
			mmap[i][j] = -1;
		}
	}
	cin >> dian >> bian;
	for (int i = 1 ; i <= bian ; i++)
	{
		int s = 0;
		int e = 0;
		int l = 0;
		cin >> s >> e >> l;
		mmap[s][e] = l;
		mmap[e][s] = l;
	}
	//
	list ok;
	list sh;
	ok.insert(1);
	for (int i = 2 ; i <= dian ; i++)
	{
		sh.insert(i);
	}
	//
	int length_sum = 0;
	while (ok.c < dian)
	{
		int min_length = 0;
		int min_start = -1;
		int min_end = -1;
		int min_end_i = -1;
		for (int si = 1 ; si <= ok.c ; si++)
		{
			int s = ok.num[si];
			for (int ei = 1 ; ei <= sh.c ; ei++)
			{
				int e = sh.num[ei];
				int length = mmap[s][e];
				if (length != -1)
				{
					if ((min_end_i == -1) || (length < min_length))
					{
						min_length = length;
						min_start = s;
						min_end = e;
						min_end_i = ei;
					}
				}
			}
		}
		cout << min(min_start, min_end) << " -> " << max(min_start, min_end) << " : " << min_length << endl;
		ok.insert(min_end);
		sh.erase(min_end);
		length_sum += min_length;
	}
	cout << "Sum: " << length_sum << endl;
	return 0;
}

