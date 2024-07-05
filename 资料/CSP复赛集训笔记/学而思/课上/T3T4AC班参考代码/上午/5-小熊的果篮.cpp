#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e5 + 5;
int n, L[N], R[N], l[N], r[N], p[N], q[N];
void connect_A(int x, int y)
{
	R[x] = y;
	L[y] = x;
}
void connect_B(int x, int y)
{
	if(x != -1)	r[x] = y;
	if(y != -1) l[y] = x;
}
int main()
{
	scanf("%d", &n);
	int now = 0;
	p[0] = -1;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
		connect_A(i-1, i);
		if(p[i] != p[i-1])
		{
			connect_B(now, i);
			now = i;
		}
	}
	connect_A(n, n+1);
	connect_B(now, n+1);
	while(r[0] <= n)
	{
		int cnt = 0;
		for(int i = r[0]; i <= n; i = r[i])
		{
			printf("%d ", i);
			connect_A(L[i], R[i]); //������������ɾ��i��
			if(R[i] == r[i])
				connect_B(l[i], r[i]);  //û�н���㣬ֱ��ɾ����һ��
			else
			{
				connect_B(l[i], R[i]); //����һ�������i��Ϊ����
				connect_B(R[i], r[i]);
			}
		}
		puts("");
		for(int i = r[0]; i <= n; i = r[i])
			if(p[l[i]] == p[i]) //���i��l[i]��ͬһ��ˮ�� 
				connect_B(l[i], r[i]); // i����������
	}
	return 0;
}
