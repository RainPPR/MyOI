#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 3e5 + 10;

int n, m;
int a[N];	// 数
int s[N];	// 前缀和

vector<int> alls;	// 下标（离散化）
vector<PII> add, query;

int find(int x)	// x 离散化后的结果
{
	int l = 0;
	int r = alls.size() - 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (alls[mid] >= x)
			r = mid;
		else
			l = mid + 1;
	}
	return r + 1;
}

int main()
{
	// 输入
	scanf("%d %d", &n, &m);
	int x, c;
	for (int i = 0 ; i < n ; ++i)
	{
		scanf("%d %d", &x, &c);
		add.push_back({x, c});

		alls.push_back(x);
	}
	int l, r;
	for (int i = 0 ; i < m ; ++i)
	{
		scanf("%d %d", &l, &r);
		query.push_back({l, r});

		alls.push_back(l);
		alls.push_back(r);
	}

	// 去重
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());

	// 处理操作
	for (auto item : add)
	{
		int x = find(item.first);
		a[x] += item.second;
	}

	// 处理前缀和
	for (int i = 1 ; i <= alls.size() ; ++i)
		s[i] = s[i - 1] + a[i];

	// 处理询问
	for (auto item : query)
	{
		int l = find(item.first);
		int r = find(item.second);
		printf("%d\n", s[r] - s[l - 1]);
	}
	return 0;
}
