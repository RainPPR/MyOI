#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-8;

int n;
double a[N][N];

bool gauss()
{
	int c, r;
	for (c = 0, r = 0 ; c < n ; ++c)
	{
		int t = r;
		for (int i = r ; i < n ; ++i)
			if (fabs(a[i][c]) > fabs(a[t][c]))
				t = i;

		if (fabs(a[t][c]) < eps)
			continue;

		for (int i = c ; i <= n ; ++i)
			swap(a[t][i], a[r][i]);
		for (int i = n ; i >= c ; --i)
			a[r][i] /= a[r][c];
		for (int i = r + 1 ; i < n ; ++i)
			if (fabs(a[i][c]) > eps)
				for (int j = n ; j >= c ; --j)
					a[i][j] -= a[r][j] * a[i][c];

		++r;
	}

	if (r < n)
		return false;

	for (int i = n - 1 ; i >= 0 ; --i)
		for (int j = i + 1 ; j < n ; ++j)
			a[i][n] -= a[i][j] * a[j][n];

	return true;
}

int main()
{
	cin >> n;
	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < n + 1 ; ++j)
			cin >> a[i][j];

	if (gauss())
	{
		for (int i = 0 ; i < n ; ++i)
		{
			if (fabs(a[i][n]) < eps)
				a[i][n] = 0.00;
			printf("%.2lf\n", a[i][n]);
		}
	}
	else
		printf("No Solution\n");
	return 0;
}
