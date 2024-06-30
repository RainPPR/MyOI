#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MR=2e5+10;
int n,Q,S,T,a[MR],d[MR];
LL delta(int D){
    if(D>0) return -1ll*D*S;
    else return -1ll*D*T;
}
int main(){
    cin>>n>>Q>>S>>T;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        d[i]=a[i]-a[i-1];
    }
    LL t=0;
    for(int i=1;i<=n;i++){
        t+=delta(d[i]);
    }
    while(Q--){
        int L,R,x;
        cin>>L>>R>>x;
        t-=delta(d[L]);
        if(R<n) t-=delta(d[R+1]);
        d[L]+=x;
        d[R+1]-=x;
        t+=delta(d[L]);
        if(R<n) t+=delta(d[R+1]);
        cout<<t<<endl;
    }
    return 0;
}