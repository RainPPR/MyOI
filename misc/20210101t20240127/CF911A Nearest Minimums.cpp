#include <cstdio>
#include <map>
#include <vector>

using namespace std;

map<int, vector<int> > mp;

int main()
{
	int n;
	scanf("%d", &n);

	int a;
	for (int i = 0 ; i < n ; ++i)
	{
		scanf("%d", &a);
		mp[a].push_back(i);
	}

	int t, cmin = 2e9;

	vector<int> m = mp.begin()->second;
	for (int i = 1 ; i < m.size() ; ++i)
	{
		t = m[i] - m[i - 1];
		cmin = (t < cmin) ? t : cmin;
	}

	printf("%d\n", cmin);
	return 0;
}
