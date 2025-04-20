#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<ctime>
//#include<windows.h>
//#include<conio.h>
//#include<bits/stdc++.h>
using namespace std;
int question[300002] = {0};
int yind[300002] = {0};
int main()
{
	//输入
	int n = 0, m = 0, k = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1 ; i <= m ; i++)
	{
		scanf("%d", question + i);
	}
	for (int i = 1 ; i <= n ; i++)
	{
		scanf("%d", yind + i);
	}
	//计算
	int maxc = -1;
	for (int bombi = 0 ; bombi <= n ; bombi++)
	{
		int cnow = 0;
		int quec = 1;
		int okcount = 0;
		for (int i = 1 ; i <= n ; i++)
		{
			if (i != bombi)
			{
				cnow += yind[i];
				cnow %= k;
				if (cnow == 0)
				{
					//开启成功
					for( ; question[quec] < i ; quec++) ;
					if(question[quec] == i)
					{
						okcount++;
						quec++;
					}
					cnow = 0;
				}
			}
		}
		//完成
		if (okcount > maxc)
		{
			maxc = okcount;
		}
	}
	//输出
	printf("%d", maxc);
	return 0;
}
