#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double x = 0;
	cin >> x;
	if (x < 0)
	{
		x = -x;
		printf("-");
	}
	double l = 0, r = (x < 1) ? 1 : x;
	while (r - l > 1e-8)
	{
		double mid = (l + r) / 2;
		if (mid * mid * mid >= x)
			r = mid;
		else
			l = mid;
	}
	printf("%.6lf", l);
	return 0;
}
