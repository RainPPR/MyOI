/*
  悬挂在屋檐下的风铃，摇晃的声音很动听。
  思念就像梅雨下不停，我的心境一片泥泞。
  散落在天际里的繁星，闪烁着你我的宿命。
  当枫叶轻盈落入湖心，近看山水一片宁静。

  ——银临 & 涵昱《苦竹林》
 */
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int q[N];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0 ; i < n ; ++i)
		scanf("%d", q + i);

	sort(q, q + n);

	int ans = 2e9;
	for (int i = 0 ; i < n - m + 1 ; ++i)
	{
		int c = q[i + m - 1] - q[i];
		ans = (c < ans) ? c : ans;
	}

	printf("%d\n", ans);
	return 0;
}
