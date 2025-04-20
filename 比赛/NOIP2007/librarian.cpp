#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int book[1001];
int len[1001];
int getlen(int n)
{
	int i = 0;
	while(n)
	{
		n /= 10;
		i++;
	}
	return i;
}
int main()
{
	int n = 0,q = 0;
	scanf("%d %d",&n,&q);
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d",book+i);
	}
	//cout << "Sort: ";
	sort(book,book+n);
	for(int i = 0 ; i < n ; i++)
	{
		//printf("%d ",book[i]);
		len[i] = getlen(book[i]);
	}
	//cout << endl;
	for(int i = 0 ; i < q ; i++)
	{
		int sl = 0;
		int num = 0;
		scanf("%d %d",&sl,&num);
		int nc = -1;
		for(int j = n-1 ; j >= 0 ; j--)
		{
			//cout << "位数比较: " << len[j] << " " << sl << endl;
			if(len[j] < sl)
			{
				break;
			}
			int cmpa = book[j];
			int cmpb = num;
			//cout << "判定：\"" << cmpb << "\"是否在\"" << cmpa << "\"的后部，";
			bool iso = true;
			while(cmpb)
			{
				if((cmpa % 10) != (cmpb % 10))
				{
					iso = false;
					break;
				}
				cmpa /= 10;
				cmpb /= 10;
			}
			//cout << "Re = " << iso << endl;;
			if(iso)
			{
				nc = book[j];
			}
		}
		//printf("结果：%d\n\n",nc);
		printf("%d\n",nc);
	}
	return 0;
}
