#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MR=100010;
const int MOD=10007;
int num[MR];
int c[MR];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",num+i);
    for(int i=1;i<=n;i++)scanf("%d",c+i);   
    if(n <= 3000){
        long long ans=0;
        for(int x=1;x<=n;x++){
            for(int z=x+2;z<=n;z+=2){
                if(c[x]!=c[z]) continue;
                ans += 1ll*(x+z)*(num[x]+num[z]);
                ans %= MOD;
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    long long ans=0;
    int cnt[MR]={};//记录每种颜色个数
    int idx[MR][101];//idx[i][j]表示颜色i第j次出现的下标位置
    for(int i=1;i<=n;i++){
        cnt[c[i]]++;
        idx[c[i]][cnt[c[i]]]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=cnt[i];j++){
            for(int k=j+1;k<=cnt[i];k++){
                int x=idx[i][j],z=idx[i][k];
                if((x+z)%2==0){
                    ans += 1ll*(x+z)*(num[x]+num[z]);
                    ans %= MOD;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}