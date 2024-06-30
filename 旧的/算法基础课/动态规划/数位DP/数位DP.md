# 数位DP

核心思想：***分情况讨论***

## 1. 问题（一）

求出 $a \sim b$ 中 $0 \sim 9$ 出现的次数

### 1.1. 转化

$\text{count}(n, x)$ 返回 $1 \sim n$ 中 $x$ 出现的次数，问题转化为（二）

### 1.2. 求解

前缀和思想：$\text{count}(b, x) - \text{count}(a - 1, x)$

## 2. 问题（二）

求出 $1 \sim n$ 中 $x$ 出现的次数

### 2.1. 举例

求 $1$ 在第 $4$ 为出现的次数

#### 2.1.1. 转化

即求 有多少形如 $1 \le xxx1yyy \le abcdefg$ 的数

#### 2.1.2. 计算

1. $xxx = 000 \sim abc - 1$，则 $yyy = 000 \sim 999$，方案数为 $abc \times 1000$

2. $xxx = abc$
   1. 若 $d < 1$，则 $abc1yyy > abc0efg$，方案数为 $0$
   2. 若 $d = 1$，则 $yyy = 000 \sim efg$，方案数为 $efg + 1$
   3. 若 $d > 1$，则 $yyy = 000 \sim 999$，方案数为 $1000$

* 总方案数为：以上两种情况相加

#### 2.1.3. 边界情况

1. 出现在最高位：第一种情况不存在
2. 若取 $0$（不能有前导零）：第一种情况为 $xxx = 001 \sim abc$

## 3. 代码

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int get(vector<int> num, int l, int r)
{
	int res = 0;
	for (int i = l ; i >= r ; --i)
		res = res * 10 + num[i];
	return res;
}

int pow10(int x)
{
	int res = 1;
	while (x--)
		res *= 10;
	return res;
}

int count(int n, int x)
{
	if (!n)
		return 0;

	vector<int> num;
	while (n)
	{
		num.push_back(n % 10);
		n /= 10;
	}

	n = num.size();

	int res = 0;
	for (int i = n - 1 - !x ; i >= 0 ; --i)
	{
		if (i < n - 1)
		{
			res += get(num, n - 1, i + 1) * pow10(i);

			if (!x)
				res -= pow10(i);
		}

		if (num[i] == x)
			res += get(num, i - 1, 0) + 1;
		else if (num[i] > x)
			res += pow10(i);
	}

	return res;
}

int main()
{
	int a, b;

	while (cin >> a >> b, a || b)
	{
		if (a > b)
			swap(a, b);

		for (int i = 0 ; i < 10 ; ++i)
			cout << count(b, i) - count(a - 1, i) << " ";
		cout << endl;
	}

	return 0;
}
```