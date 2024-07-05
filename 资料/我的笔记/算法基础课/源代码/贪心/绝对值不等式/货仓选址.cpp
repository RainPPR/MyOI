#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n;
int t[N];
inline int ABS(int number)
{
	return (number < 0) ? -number : number;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0 ; i < n ; ++i)
		scanf("%d", t + i);
	sort(t, t + n);
	int cpos = t[n >> 1];
	int res = 0;
	for (int i = 0 ; i < n ; ++i)
		res += ABS(t[i] - cpos);
	printf("%d\n", res);
	return 0;
}
