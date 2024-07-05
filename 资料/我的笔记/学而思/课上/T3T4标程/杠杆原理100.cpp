#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<ctime>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long LL;
const int MR=5000+5;
int n,m,L,F,W,a[MR],b[MR],c[MR],d[MR];
int dp[MR][MR],l[MR],f[MR];

int main(){
    scanf("%d%d%d",&L,&F,&W);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",a+i,b+i);
    scanf("%d",&m);
    for(int i=1;i<=m;i++) scanf("%d%d",c+i,d+i);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=b[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-b[i]]+a[i]);
        }
    }
    for(int j=0;j<=W;j++) l[j]=dp[n][j];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++){
        for(int j=0;j<=W;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=d[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-d[i]]+c[i]);
        }
    }
    for(int j=0;j<=W;j++) f[j]=dp[m][j];
    long long ans=0;
    for(int i=0;i<=W;i++){
        ans=max(ans,1ll*(L+l[i])*(F+f[W-i]));
    }
    printf("%lld\n",ans);
    return 0;
}