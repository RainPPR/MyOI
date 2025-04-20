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
int main()
{
	int n = 0;
	int num[1000] = {0};
	cin >> n;
	for (int i = 0 ; i < n ; i++)
	{
		cin >> num[i];
	}
	int count = 0;
	for (int k = 0 ; k < n ; k++)
	{
		bool ov = true;
		for (int i = 0 ; i < n & ov ; i++)
		{
			for (int j = i + 1 ; j < n & ov ; j++)
			{
				if (num[i] != num[k] && num[j] != num[k] && i != k && j != k && ov)
				{
					if (num[k] == num[i] + num[j])
					{
						count++;
						ov = false;
					}
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}
