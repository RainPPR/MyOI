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
//在所有留下的画的价值都大于等于y的前提下
//要让所有留下的画距离都大于等于D
//判断最多能留下的画的数量是否大于等于m
bool check(int y){
    int cnt=0,pre=-1e9;
    for(int i=1;i<=n;i++){
        if(e[i].v<y) continue;
        if(e[i].x-pre<D) continue;
        cnt++;
        pre=e[i].x;
    }
    return cnt>=m;
}
int main() {
    cin>>n>>m>>D;
    for(int i=1;i<=n;i++) cin>>e[i].x>>e[i].v;
    sort(e+1,e+1+n,cmp);
    LL l=-1,r=1e9+10;
    while(l+1<r){
        LL mid=(l+r)/2;
        if(check(mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<l<<endl;
    return 0;
}