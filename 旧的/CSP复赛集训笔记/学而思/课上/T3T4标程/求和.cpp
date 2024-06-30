#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MR=100010;
const int MOD=10007;
long long num[MR],c[MR];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",num+i);
	for(int i=1;i<=n;i++)scanf("%lld",c+i);	
	long long ans=0;
	for(int x=1;x<=n;x++){
		for(int z=x+2;z<=n;z+=2){
			if(c[x]!=c[z]) continue;
			ans += (x+z)*(num[x]+num[z]);
			ans %= MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}