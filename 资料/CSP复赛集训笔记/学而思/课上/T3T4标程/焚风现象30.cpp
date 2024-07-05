#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MR=2e5+10;
int n,Q,S,T,a[MR];
LL f(){
    LL t=0;
    for(int i=0;i<=n-1;i++){
        if(a[i]<a[i+1]) t-=1ll*(a[i+1]-a[i])*S;
        else t+=1ll*(a[i]-a[i+1])*T;
    }
    return t;
}

int main(){
    cin>>n>>Q>>S>>T;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    while(Q--){
        int L,R,x;
        cin>>L>>R>>x;
        for(int i=L;i<=R;i++){
            a[i]+=x;
        }
        cout<<f()<<endl;
    }
    return 0;
}