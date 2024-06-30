#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
//��Xd-Xc=i����ô��Xb=Xa+2i��Xd=Xc+i
//����Xb-Xa<(Xc-Xb)/3,�õ�4Xb-3Xa<Xc������õ�Xa+8i<Xc��Xa+9i<Xd<=n
const int N = 15005, M = 40005;
int n, m, x[M], num[N][4], cnt[N], s[N];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &x[i]);
		cnt[x[i]]++;
	}
	for(int i = 1; i * 9 < n; i++) //ö��Xd-Xc�Ĳ�ֵ
	{
		//�����������Ϊi�Ķ�Ԫ�������Ȼ����ǰ׺�� 
		s[9 * i] = 0;
		for(int j = 9 * i + 1; j <= n; j++) //ͳ��Xd=j�Ķ�Ԫ�������ǰ׺�� 
			s[j] = s[j-1] + cnt[j - i] * cnt[j];
		for(int a = 1; a + 9 * i < n; a++)
		{
			num[a][0] += cnt[a+2*i] * (s[n] - s[a + 9 * i]);
			num[a+2*i][1] += cnt[a] * (s[n] - s[a + 9 * i]);
		}
		s[0] = 0;
		for(int j = 1; j <= n - 9 * i; j++)
			s[j] = s[j-1] + cnt[j] * cnt[j + 2 * i];
		for(int d = n; d - 9 * i > 1; d--)
		{
			num[d][3] += cnt[d-i] * s[d - 9 * i - 1];
			num[d-i][2] += cnt[d] * s[d - 9 * i - 1];
		}
	}
	for(int i = 1; i <= m; i++)
		printf("%d %d %d %d\n", num[x[i]][0], num[x[i]][1], num[x[i]][2], num[x[i]][3]);
	return 0;
}
