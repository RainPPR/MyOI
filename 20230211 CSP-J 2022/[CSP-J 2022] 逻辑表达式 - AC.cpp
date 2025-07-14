#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define N (int)1e6 + 1
char str[N];
int sum1;
int sum2;
int dfs(int l, int r)
{
	int x = 0, orpos = 0, andpos = 0; //记录括号层数、最后一个 | 出现的位置、最后一个 & 出现的位置
	for (int i = l; i <= r; ++i) //遍历左右区间查找运算符
	{
		if (str[i] == '(')
		{
			++x;//增加一层括号
		}
		else
		{
			if (str[i] == ')')
			{
				--x;//减少一层括号
			}
			else
			{
				if (!x)  //不在括号中
				{
					if (str[i] == '|')
					{
						orpos = i;
					}
					else
					{
						if (str[i] == '&')
						{
							andpos = i;
						}
					}
				}
			}
		}
	}
	if (orpos)  //注意，因为 | 比 &优先级低，要先判断存不存在 |
	{
		if (str[orpos] == '|')
		{
			int tmp1 = dfs(l, orpos - 1);//遍历左区间
			if (tmp1 == 1)  //如果是 1，触发了 | 短路
			{
				++sum1;
				return 1;//不需要计算右区间，直接返回 1
			}
			else
			{
				int tmp2 = dfs(orpos + 1, r);//计算右区间
				return (tmp1 | tmp2);
			}
		}
	}
	if (andpos)
	{
		if (str[andpos] == '&')
		{
			int tmp1 = dfs(l, andpos - 1);
			if (tmp1 == 0)  //如果是 0，触发了 & 短路
			{
				++sum2;
				return 0;//不需要计算右区间，直接返回 0
			}
			else
			{
				int tmp2 = dfs(andpos + 1, r);
				return (tmp1 & tmp2);
			}
		}
	}
	//不在括号内的运算符不存在
	if (str[l] == '(' && str[r] == ')')  //如果都被括号包裹着
	{
		return dfs(l + 1, r - 1);//去掉括号
	}
	else
	{
		return str[l] - '0';//否则左右区间一定重合，返回数字就行了
	}
}
int main(int argc, const char *argv[])
{
	scanf("%s", str + 1);
	int len = strlen(str + 1);
	int sum = dfs(1, len);
	printf("%d\n%d %d\n", sum, sum2, sum1); //注意！一定要开个 sum 把dfs结果先记下来，否则直接输出会导致 UB
	return 0;
}
