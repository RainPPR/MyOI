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
LL s[MR];
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        cin>>b[i];
        s[i]=s[i-1]+b[i];
    }
    if(k==1){
        LL sum=a[n];
        for(int i=1;i<=n;i++){
            sum+=b[i];
        }
        cout<<sum<<endl;
        return 0;
    }
    if(k==2){
        LL ans=1e18;
        for(int i=n;i>=1;i--){
            LL t1=a[n]+s[n]-s[i];
            LL t2=t1-a[i];
            if(t2>=s[i]){
                ans=min(t1,ans);
            }
            else{
                ans=min(t1+(s[i]-t2+1)/2,ans);
            }
            
        }
        cout<<ans<<endl;
        return 0;
    }
    return 0;
}