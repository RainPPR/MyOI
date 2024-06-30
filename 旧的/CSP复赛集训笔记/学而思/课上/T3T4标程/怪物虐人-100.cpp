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
const int MR=501;
const int INF=0x3f3f3f3f;
int n,k;
int T[MR];
int dp[501][501],maxT[501][501];
//dp[i][j]表示用j天打前i个怪物的最小花费
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>T[i];
    for(int i=1;i<=n;i++){
        maxT[i][i]=T[i];
        for(int j=i+1;j<=n;j++){
            maxT[i][j]=max(maxT[i][j-1],T[j]);
        }
    }
    memset(dp,INF,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i && j<=k;j++){
            //设第j天打从p到i个怪物
            for(int p=1;p<=i;p++){
                dp[i][j]=min(dp[i][j],dp[p-1][j-1]+maxT[p][i]*(i-p+1));
            }
            //printf("%d ",dp[i][j]);
        }
        //printf("\n");
    }
    printf("%d\n",dp[n][k]);
    return 0;
}