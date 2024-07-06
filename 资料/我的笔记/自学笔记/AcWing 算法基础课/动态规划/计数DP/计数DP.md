# 计数DP
## 整数划分
#### 完全背包解法
问题转化为：有容量是 $n$ 的背包，有物品体积是 $1,2,\dots,n$ 且无限个，求恰好装满背包的方案。
1. 状态表示
$f_{i,j}$ 表示只从 $1\sim i$ 中选，且总和等于j的方案数数。
2. 状态计算
`f[i][j] = f[i - 1][j] + f[i][j - i];`
```cpp
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010, MOD = 1e9 + 7;
int n;
int f[N];
int main()
{
	scanf("%d", &n);
	f[0] = 1;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = i ; j <= n ; ++j)
			f[j] = (f[j] + f[j - i]) % MOD;
	printf("%d\n", f[n]);
	return 0;
}
```
#### 计数DP解法
1. 状态表示
$f_{i,j}$ 表示：所有总和是 $i$，并且恰好表示成 $j$ 个数的和方案
2. 状态计算
   1. 最小值等于1：$f_{i,j}=f_{i-1,j-1}$
   2. 最小值大于1：
   `f[i][j] = f[i - 1][j - 1] + f[i - j][j];`
3. $ans = f_{n,1}+f_{n,2}+f_{n,3}+\dots+f_{n,n}$
```cpp
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010, MOD = 1e9 + 7;
int n;
int f[N][N];
int main()
{
	scanf("%d", &n);
	f[0][0] = 1;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= i ; ++j)
			f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % MOD;
	int ans = 0;
	for (int i = 1 ; i <= n ; ++i)
		ans = (ans + f[n][i]) % MOD;
	printf("%d\n", ans);
	return 0;
}
```