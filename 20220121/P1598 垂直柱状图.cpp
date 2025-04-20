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
	int tong[26] = {0};
	int maxt = -1;
	for (int i = 0 ; i < 4 ; i++)
	{
		string temp;
		getline(cin, temp);
		for (int j = 0 ; j < temp.size() ; j++)
		{
			if (temp[j] >= 'A' && temp[j] <= 'Z')
			{
				tong[temp[j] - 'A']++;
				maxt = max(maxt, tong[temp[j] - 'A']);
			}
		}
	}
	while (maxt > 0)
	{
		for (int i = 0 ; i < 26 ; i++)
		{
			if (tong[i] >= maxt)
			{
				cout << "*";
				if (i != 25)
				{
					cout << " ";
				}
			}
			else
			{
				cout << " ";
				if (i != 25)
				{
					cout << " ";
				}
			}
		}
		cout << endl;
		maxt--;
	}
	/*´òÓ¡¸öÊý
	for(int i = 0 ; i < 25 ; i++)
	{
		cout << tong[i] << " ";
	}
	cout << tong[25] << endl;
	*/
	for(int i = 0 ; i < 25 ; i++)
	{
		cout << char(i+'A') << " ";
	}
	cout << "Z";
	return 0;
}
