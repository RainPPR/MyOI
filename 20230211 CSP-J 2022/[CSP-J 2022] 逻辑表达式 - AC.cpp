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
	int x = 0, orpos = 0, andpos = 0; //��¼���Ų��������һ�� | ���ֵ�λ�á����һ�� & ���ֵ�λ��
	for (int i = l; i <= r; ++i) //��������������������
	{
		if (str[i] == '(')
		{
			++x;//����һ������
		}
		else
		{
			if (str[i] == ')')
			{
				--x;//����һ������
			}
			else
			{
				if (!x)  //����������
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
	if (orpos)  //ע�⣬��Ϊ | �� &���ȼ��ͣ�Ҫ���жϴ治���� |
	{
		if (str[orpos] == '|')
		{
			int tmp1 = dfs(l, orpos - 1);//����������
			if (tmp1 == 1)  //����� 1�������� | ��·
			{
				++sum1;
				return 1;//����Ҫ���������䣬ֱ�ӷ��� 1
			}
			else
			{
				int tmp2 = dfs(orpos + 1, r);//����������
				return (tmp1 | tmp2);
			}
		}
	}
	if (andpos)
	{
		if (str[andpos] == '&')
		{
			int tmp1 = dfs(l, andpos - 1);
			if (tmp1 == 0)  //����� 0�������� & ��·
			{
				++sum2;
				return 0;//����Ҫ���������䣬ֱ�ӷ��� 0
			}
			else
			{
				int tmp2 = dfs(andpos + 1, r);
				return (tmp1 & tmp2);
			}
		}
	}
	//���������ڵ������������
	if (str[l] == '(' && str[r] == ')')  //����������Ű�����
	{
		return dfs(l + 1, r - 1);//ȥ������
	}
	else
	{
		return str[l] - '0';//������������һ���غϣ��������־�����
	}
}
int main(int argc, const char *argv[])
{
	scanf("%s", str + 1);
	int len = strlen(str + 1);
	int sum = dfs(1, len);
	printf("%d\n%d %d\n", sum, sum2, sum1); //ע�⣡һ��Ҫ���� sum ��dfs����ȼ�����������ֱ������ᵼ�� UB
	return 0;
}
