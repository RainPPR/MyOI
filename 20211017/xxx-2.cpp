#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
int main()
{
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll n = 0;
	cin >> n;
	if(n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	if(n == 2)
	{
		cout << 2 << endl;
		return 0;
	}
	ll fb[10000] = {0};
	fb[0] = 0;
	fb[1] = 1;
	fb[2] = 1;
	ll sum = 2;
	for(int i = 3 ; i <= n ; i++)
	{
		fb[i] = fb[i-1]+fb[i-2];
		sum += fb[i];
	}
	cout << sum << endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
