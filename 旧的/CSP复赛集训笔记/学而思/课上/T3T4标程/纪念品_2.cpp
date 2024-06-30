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


int main(){
	int T,n,m;
	scanf("%d%d%d",&T,&n,&m);
	if(T==1){
		printf("%d\n",m);
		return 0;
	}
	if(n==1){
		int price[101];
		for(int i=1;i<=T;i++){
			scanf("%d",&price[i]);
		}
		price[0]=2e9;
		price[T+1]=-1;
		//m是持有金币
		//cnt是持有纪念品数量
		int cnt=0;
		for(int i=1;i<=T;i++){
			//如果明天价格比今天高
			//就全买，然后第二天全卖
			if(price[i+1]>price[i]){
				//今天全买
				cnt+=m/price[i];
				m-=cnt*price[i];
				//明天全卖
				m+=cnt*price[i+1];
				cnt=0;
			}
		}
		printf("%d\n",m);
		return 0;
	}
	if(T==2){
		int price[2][101];
		int dp[101][1001]={};
		for(int i=1;i<=n;i++){
			scanf("%d",&price[0][i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&price[1][i]);
		}
		
		//dp[i][j]表示考虑前i种，花j元购买
		//可以在第2天卖得的最大收益
		//以第1天价格为体积，第2天与第1天差值为价值
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				dp[i][j]=dp[i-1][j];
				if(j>=price[0][i])
				    dp[i][j]=max(dp[i-1][j],dp[i][j-price[0][i]]+price[1][i]-price[0][i]);
			}
		}
		printf("%d\n",m+dp[n][m]);
	}
	return 0;
}