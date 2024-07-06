# KMP字符串
## 暴力算法
```cpp
// 在 s[n]（长文本）中查找 p[m]（模式串）
// n 是 s 的长度；m 是 p 的长度
for (int i = 1 ; i <= n ; ++i)
{
	bool flag = true;
	for (int j = 1 ; j <= m ; ++j)
		if (s[i] != p[j])
		{
			flag = false;
			break;
		}
}
```
## KMP思路
下标习惯上从 $1$ 开始
#### next数组含义
* $next_i$ 表示以 $i$ 为终点的后缀和从 $1$ 开始的前缀相等，最长的后缀长度
* 即 $p_{i \text{ } \sim \text{ } j} = p_{i-j+1 \text{ } \sim \text{ } i}$
## 代码
```cpp
#include<iostream>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
char p[N], s[M];
int ne[N];

int main()
{
	scanf("%d", &n);
	scanf("%s", p + 1);
	scanf("%d", &m);
	scanf("%s", s + 1);
	
	// 求next
	for (int i = 2, j = 0 ; i <= n ; ++i)
	{
		while (j && (p[i] != p[j + 1]))
			j = ne[j];
		if (p[i] == p[j + 1])
			++j;
		ne[i] = j;
	}
	
	// KMP匹配过程
	for (int i = 1, j = 0 ; i <= m ; ++i)
	{
		while (j && (s[i] != p[j + 1]))
			j = ne[j];
		if (s[i] == p[j + 1])
			++j;
		if (j == n)
		{
			// 匹配成功
			printf("%d ", i - n);
			j = ne[j];
		}
	}
	
	return 0;
}
```