#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 1e5 + 10;

int n, m;

unordered_map<ll, int> id2sub;		// 考生号 转 下标
unordered_map<ll, int> unix2sub[N];	// 每个考生 Unix时间戳 转 下标

unordered_map<int, int> point[N];	// 每个 考生 每场 考试 两次分数 总和

int main()
{
	scanf("%d %d", &n, &m);
	n = 2 * n;

	int exam, s;
	ll unix, id;
	for (int i = 0 ; i < n ; ++i)
	{
		scanf("%10lld%14lld%3d %d", &unix, &id, &exam, &s);

		if (id2sub.count(id) == 0)
			id = id2sub[id] = id2sub.size();
		else
			id = id2sub[id];

		if (unix2sub[id].count(unix) == 0)
			unix = unix2sub[id][unix] = unix2sub[id].size();
		else
			unix = unix2sub[id][unix];

		point[id][unix] += s;
	}

	unordered_set<int> my_points;
	vector<int> my_points_ans;
	for (int i = 0 ; i < m ; ++i)
	{
		scanf("%d", &s);
		my_points.insert(s);
		my_points_ans.push_back(s);
	}

	for (pair<ll, int> i : id2sub)
	{
		unordered_set<int> points;
		unordered_map<int, ll> unixs;

		for (pair<ll, int> j : unix2sub[i.second])
		{
			s = ceil(point[i.second][j.second] / 2.0);
			points.insert(s);
			unixs[s] = j.first;
		}

		if (points == my_points)
		{
			for (int i = 0 ; i < m ; ++i)
				printf("%lld\n", unixs[my_points_ans[i]]);
			break;
		}
	}

	return 0;
}
