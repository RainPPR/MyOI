# 区间DP
状态 $f_{i,j}$ 表示一个区间
区间DP一般做法：先循环区间长度，再循环区间左端点
## 石子合并
#### 状态表示
1. 状态表示 $f_{i,j}$ 二维表示一个区间
   * 集合：所有将区间 $[i,j]$ 内的石子合并的方式
   * 属性：代价的最小值
2. 状态计算（集合划分）
   * 把集合划分成两个，可以在不同位置划分
   * $[i,j] \implies [i,k]+[k+1,j]$
   * $f_{i,j} = \min(f_{i,k},f_{k+1,j})+sum(i,j)\text{（}k = \{i,\dots,j-1\}\text{）}$
   * 前缀和：$f_{i,j} = \min(f_{i,k},f_{k+1,j})+s_j-s_{i-1}\text{（}k = \{i,\dots,j-1\}\text{）}$
3. $ans = f_{1,n}$
#### 因为每次划分区间都会把这一个区间划分为更小的两部分，所以区间从小到大枚举，每次用到的数据一定是已经计算过的。
#### 正确代码
```cpp
#include<cstdio>
#include<iostream>
using namespace std;
const int N = 310;
int n;
int s[N];
int f[N][N];
int main()
{
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d", s + i);
	for (int i = 1 ; i <= n ; ++i)
		s[i] += s[i - 1];
	for (int len = 2 ; len <= n ; ++len)			// 枚举区间长度
		for (int i = 1 ; i + len - 1 <= n ; ++i)	// 枚举区间开头
		{
			int l = i, r = i + len - 1;				// 区间两端点
			f[l][r] = 2e9;
			for (int k = l ; k < r ; ++k)			// 枚举划分位置
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
		}
	printf("%d\n", f[1][n]);
	return 0;
}
```