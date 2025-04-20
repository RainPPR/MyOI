/*
  于盛夏之末，入夜仍灼热。
  又一场离合，开始凄恻。
  是扇底闪躲，或雨水摧折。
  哪里都值得，恋恋不舍。

  ——银临《腐草为萤》
 */
#include <cstdio>

using namespace std;

const int N = 5e5 + 10;

int n;
int x[N], a[N];

// 解决 n = 2 的问题
namespace Solve1
{
	bool Main()
	{
		// 递减
		if (a[1] > a[2])
			printf("0 %d", x[1]);
		// 递增
		else
			printf("%d 0", x[2]);
		return true;
	}
}

// 解决 单调递增、单峰 的问题
namespace Solve2
{
	bool Main()
	{
		// 寻找峰值
		int max_x = -1, max_a = -1, max_i = 0;
		for (int i = 1 ; i <= n ; ++i)
			if ((max_x == -1) || (a[i] > max_a))
				max_x = x[i], max_a = a[i], max_i = i;
		// 除峰值处为 0 外，其余均为峰值坐标
		for (int i = 1 ; i < max_i ; ++i)
			printf("%d ", max_x);
		printf("0 ");
		for (int i = max_i + 1 ; i < n ; ++i)
			printf("%d ", max_x);
		printf("%d", max_x);
		return true;
	}
}

// 暴力模拟
namespace Solve3
{
	// 储存临时坐标；剩余萤火虫数量；是否存在
	int xt[N], cnt;
	// 储存每一个萤火虫，左侧相邻的萤火虫坐标、右侧相邻的萤火虫坐标
	int le[N], rt[N];
	// 储存每一个萤火虫是否存在
	bool is[N];
	// 储存答案
	int ans[N];
	// 初始化
	bool init()
	{
		cnt = n;
		for (int i = 1 ; i <= n ; ++i)
			le[i] = i - 1, rt[i] = i + 1, is[i] = true, xt[i] = ::x[i];
		return true;
	}

	bool Main()
	{
		// 初始化数据
		init();
		// 重复运算直至仅剩一个萤火虫
		while (cnt > 1)
		{
			// 枚举每一只萤火虫，判断应该向那个方向走，储存在临时坐标数组中
			for (int i = 1 ; i <= n ; ++i)
			{
				if (is[i])
				{
					int l = le[i], r = rt[i];
					// 左侧大，向左走；右侧大，向右走
					int s = (a[l] > a[r]) ? -1 : 1;	// 向左或向右走
					int p = (a[l] > a[r]) ? l : r;	// 左边或右边的萤火虫下表
					if (a[i] < a[p])
					{
						xt[i] = x[i] + s;
						// 如果相遇，亮度 a 较小者消失（更新其左、右萤火虫的右、左坐标）
						if (xt[i] == x[p])
						{
							int tl = le[i], tr = rt[i];
							rt[tl] = tr, le[tr] = tl;
							ans[i] = xt[i];
							is[i] = false;
							--cnt;
						}
					}
				}
			}
			// 更新数据：将临时数组的数据复制到数组中
			for (int i = 1 ; i <= n ; ++i)
				x[i] = xt[i];
		}
		for (int i = 1 ; i < n ; ++i)
			printf("%d ", ans[i]);
		printf("%d", ans[n]);
		return true;
	}
}

int main()
{
	// 判断单调递增、单峰性
	int isTwo = 0;
	// 输入
	scanf("%d", &n);
	x[0] = -2e9;
	x[n + 1] = 2e9;
	a[0] = a[n + 1] = -2e9;
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d", x + i);
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", a + i);
		if ((isTwo == 0 && a[i] < a[i - 1]) || (isTwo == 1 && a[i] > a[i - 1]))
			++isTwo;
	}

	// 分类计算
	if (n == 2)
		Solve1::Main();
	//else if (isTwo != 2)
	//	Solve2::Main();
	else
		Solve3::Main();
	return 0;
}
