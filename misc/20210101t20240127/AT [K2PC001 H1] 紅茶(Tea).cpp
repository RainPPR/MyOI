#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

pair<int, int> i2p(int i)
{
	int group = (sqrt(8 * i - 7) + 1) / 2;
	int count = group * (group + 1) / 2;
	int right = count - i;
	return make_pair(right + 1, group - right);
}

int p2i(pair<int, int> p)
{
	int group = p.first + p.second - 1;
	int right = p.first - 1;
	int count = group * (group + 1) / 2;
	return count - right;
}

int main()
{
	int i, j;
	scanf("%d %d", &i, &j);

	pair<int, int> ii, jj;
	ii = i2p(i), jj = i2p(j);

	pair<int, int> ij;
	ij = make_pair(ii.first + jj.first, ii.second + jj.second);

	int ans = p2i(ij);
	printf("%d\n", ans);
	return 0;
}
