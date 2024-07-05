#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int MR=1e6+10;
typedef long long LL;
int n,k,a[MR],b[MR];
bool check(LL x){
    LL remain=0;//最后工人可以用在下个设施的时间
    LL sum=0;//需要的工人数量
    for(int i=n;i>=1;i--){
        if(x-a[i]<=0) return false;
        LL p=x-a[i];//每个工人可以用在第i个设施的时间
        if(b[i]<=remain){//b比较小的话，上个设施最后工人有可能能够检查很多设施
            remain-=b[i];
            continue;
        }
        int t=(b[i]-remain)/p;
        int r=(b[i]-remain)%p;
        sum+=t;
        if(r!=0){//最后一个工人可以在下个设施检查remain时间
            sum++;
            remain=p-r;
        }
        else{
            remain=0;
        }
    }
    return sum<=k;
}
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    LL l=0,r=1e18+10;
    while(l+1<r){
        LL mid=(l+r)/2;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    cout<<r<<endl;
    return 0;
}