#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n;
vector<PII> segs;

void merge(vector<PII> &segs)
{
	vector<PII> res;

	sort(segs.begin(), segs.end());

	int st = -2e9, ed = -2e9;
	for (auto seg : segs)
		if (ed < seg.first)
		{
			if (st != -2e9)
				res.push_back({st, ed});
			st = seg.first, ed = seg.second;
		}
		else if (seg.second > ed)
			ed = seg.second;

	if (st != -2e9)
		res.push_back({st, ed});

	segs = res;
}

int main()
{
	scanf("%d", &n);

	int l, r;
	for (int i = 0 ; i < n ; ++i)
	{
		scanf("%d %d", &l, &r);
		segs.push_back({l, r});
	}

	merge(segs);

	printf("%d\n", segs.size());
	return 0;
}
