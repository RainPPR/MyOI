#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double x = 0;
	cin >> x;
	double l = 0, r = (x < 1) ? 1 : x;
	while (r - l > 1e-10)
	{
		double mid = (l + r) / 2;
		if (mid * mid >= x)
			r = mid;
		else
			l = mid;
	}
	printf("%.8lf", l);
	return 0;
}
