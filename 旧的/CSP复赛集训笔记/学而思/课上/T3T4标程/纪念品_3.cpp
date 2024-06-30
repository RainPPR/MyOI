#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long LL;
const int NR=105;
const int MR=1e4+5;
int price[NR][NR];
int dp[NR][MR];
//dp[i][j]表示考虑前i个物品，花费不超过j元时的最大价值
//我们用明天价格减今天价格作为价值


int main(){
	int T,n,m;
	scanf("%d%d%d",&T,&n,&m);
	for(int k=1;k<=T;k++){
		for(int i=1;i<=n;i++){
			scanf("%d",&price[k][i]);
		}
	}

	for(int k=1;k<T;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(j>=price[k][i])
					dp[i][j]=max(dp[i-1][j], dp[i][j-price[k][i]]+price[k+1][i]-price[k][i]);
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		m+=dp[n][m];
	}
	printf("%d\n",m);
	return 0;
}