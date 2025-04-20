#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int main()
{
	srand(time(0));
	freopen("transfer.in","w",stdout);
	cout << 100000 << endl;
	int time = 0;
	for(int i = 0 ; i < 100000 ; i++)
	{
		printf("%d %d %d",rand()%2,rand()%10000+1,time+=rand()%9999+1);
	}
	fclose(stdout);
	return 0;
}
