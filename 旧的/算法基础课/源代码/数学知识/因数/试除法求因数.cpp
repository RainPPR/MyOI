#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef vector<int> vl;
vl get_divisors(int n)
{
	vl res;
	for (int i = 1 ; i <= n / i ; ++i)
		if (n % i == 0)
		{
			res.push_back(i);
			if (i != n / i)
				res.push_back(n / i);
		}
	sort(res.begin(), res.end());
	return res;
}
int main()
{
	int d = 0;
	scanf("%d", &d);
	while (d--)
	{
		int x = 0;
		scanf("%d", &x);
		vl ans = get_divisors(x);
		for (auto t : ans)
			printf("%d ", t);
		printf("\n");
	}
	return 0;
}
