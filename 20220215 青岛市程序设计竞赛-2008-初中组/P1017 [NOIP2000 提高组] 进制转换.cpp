#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0;
	int r = 0;
	scanf("%d %d",&n,&r);
	printf("%d=",n);
	bool a = false;
	string str;
	while (n)
	{
		int c = n % r;
		if (a)
		{
			c = !c;
			a = false;
		}
		if (c == -1)
		{
			c = -c;
			a = true;
		}
		str = str + char(c + '0');
		n /= r;
	}
	while (str[str.size() - 1] == '0')
	{
		str.pop_back();
	}
	char out[256] = {0};
	strcpy(out,string(str.rbegin(),str.rend()).data());
	printf("%s(base%d)",out,r);
	return 0;
}
