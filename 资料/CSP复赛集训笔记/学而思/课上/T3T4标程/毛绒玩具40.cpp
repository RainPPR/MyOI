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
int f(){//计算最小需要拿多少
    int last=0;
    for(int i=1;i<=m;i++){
        //将第toy[i]种玩具填在b数组
        for(int j=1;j<=toycnt[toy[i]];j++){
            last++;
            b[last]=toy[i];
        }
    }
    int ret=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]) ret++;
    }
    return ret;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        toycnt[a[i]]++;
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