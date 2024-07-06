#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int N = 1e5 + 10;
int n;
struct Range
{
	int l, r;
	bool operator < (const Range &W) const
	{
		return l < W.l;
	}
} range[N];
int main()
{
	scanf("%d", &n);
	for (int i = 0 ; i < n ; ++i)
		scanf("%d %d", &range[i].l, &range[i].r);
	sort(range, range + n);
	priority_queue<int, vector<int>, greater<int>> heap;
	for (int i = 0 ; i < n ; ++i)
	{
		Range r = range[i];
		if (heap.empty() || (heap.top() >= r.l))
			heap.push(r.r);
		else
		{
			int t = heap.top();
			heap.pop();
			heap.push(r.r);
		}
	}
	printf("%d\n", heap.size());
	return 0;
}
