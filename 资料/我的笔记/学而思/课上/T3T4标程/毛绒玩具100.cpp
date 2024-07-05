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
const int MR=1e5+10;
const int INF=0x3f3f3f3f;
int n,m,a[MR];
int toycnt[25];//每种玩具的个数
int s[MR][25];//s[i][j]表示前i个第j种玩具有多少个
int dp[1100000],setcnt[1100000];//setcnt[S]表示集合S的玩具总数

int f(int S){
    if(dp[S]<INF) return dp[S];
    int ret=INF;
    for(int i=1;i<=m;i++){
        int mask=1<<(i-1);
        if(S&mask){
            int last=setcnt[S^mask],c=toycnt[i];
            ret=min(ret,c-s[last+c][i]+s[last][i]+f(S^mask));
        }
    }
    return dp[S]=ret;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        toycnt[a[i]]++;
        for(int j=1;j<=m;j++){
            if(j==a[i]) s[i][j]=s[i-1][j]+1;
            else s[i][j]=s[i-1][j];
        }
    }
    for(int S=0;S<(1<<m);S++){
        for(int i=1;i<=m;i++){
            int mask=1<<(i-1);
            if(S&mask){
                setcnt[S]+=toycnt[i];
            }
        }
    }
    memset(dp,INF,sizeof(dp));
    dp[0]=0;
    int ans=f((1<<m)-1);
    cout<<ans<<endl;
    return 0;
}