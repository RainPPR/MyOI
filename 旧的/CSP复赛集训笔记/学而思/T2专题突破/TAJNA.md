# TAJNA
```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N = 110;
char str[N], mp[N][N];
int len, r;
int main()
{
	scanf("%s", str);
	len = strlen(str);
	for (int i = sqrt(len) ; i >= 1 ; --i)
	{
		if (len % i == 0)
		{
			r = i;
			break;
		}
	}
	for (int i = 0 ; i < r ; ++i)
		for (int j = 0 ; j < len ; j += r)
			putchar(str[i + j]);
	return 0;
}
```