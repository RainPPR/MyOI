#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int MR=1e5+10;
typedef long long LL;
int n,m,D;
struct E
{
    int x,v;
}e[MR];
bool cmp(E a,E b){
    return a.x<b.x;
}
int ans;

void dfs(int p,int last,int minv){
    if(p>m){
        ans=max(ans,minv);
        return;
    }
    for(int i=last+1;i<=n;i++){
        if(e[i].x-e[last].x<D) continue;
        dfs(p+1,i,min(minv,e[i].v));
    }
}
int main() {
    cin>>n>>m>>D;
    for(int i=1;i<=n;i++) cin>>e[i].x>>e[i].v;
    sort(e+1,e+1+n,cmp);
    e[0].x=-1e9;
    if(m==1){
        ans=-1;
        for(int i=1;i<=n;i++){
            ans=max(e[i].v,ans);
        }
        cout<<ans<<endl;
        return 0;
    }
    if(m==n){
        int minv=1e9;
        bool flag=1;
        for(int i=1;i<=n;i++){
            minv=min(minv,e[i].v);
            if(e[i].x-e[i-1].x<D){
                flag=0;
                break;
            }
        }
        cout<<minv<<endl;
        return 0;
    }
    ans=-1;
    dfs(1,0,1e9);
    cout<<ans<<endl;
    return 0;
}