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
	//����
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
	//����
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
					//�����ɹ�
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
		//���
		if (okcount > maxc)
		{
			maxc = okcount;
		}
	}
	//���
	printf("%d", maxc);
	return 0;
}
