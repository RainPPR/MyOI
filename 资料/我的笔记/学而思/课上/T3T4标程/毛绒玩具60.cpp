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
int n,m,a[MR],b[MR];
int toy[25];//排列好后玩具种类的顺序
int toycnt[25];//每种玩具的个数
int s[25][MR];//s[i][j]表示第i种在前j个中有多少个
int f(){//计算最小需要拿多少
    int last=0, ret=0;
    for(int i=1;i<=m;i++){
        int c=toycnt[toy[i]];//当前玩具的数量
        //第toy[i]种玩具将会填在last+1到last+c
        //要换的数量等于 c 减去这段内第toy[i]种玩具的数量
        ret += c - (s[toy[i]][last+c] - s[toy[i]][last]);
        last += c;
    }
    return ret;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        toycnt[a[i]]++;
        for(int j=1;j<=m;j++){
            if(j==a[i]) s[j][i]=s[j][i-1]+1;
            else s[j][i]=s[j][i-1];
        }
    }
    for(int i=1;i<=m;i++){
        toy[i]=i;
    }
    int ans=n+1;
    do{
        ans=min(ans,f());
    }while(next_permutation(toy+1,toy+1+m));
    cout<<ans<<endl;
    return 0;
}