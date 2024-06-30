#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MR=100010;
const int MOD=10007;
long long num[MR],c[MR];
struct Color{
	long long k,sum_n,sum_x,sum_nx;
	Color(long long k=0,long long n=0,long long x=0):k(k),sum_n(n),sum_x(x),sum_nx(n*x){}

	long long sum(){
		if(k<2) return 0;
		return (k-2)*sum_nx+sum_n*sum_x;
	}


};
Color odd[MR];
Color even[MR];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",num+i);
	for(int i=1;i<=n;i++)scanf("%lld",c+i);	
	long long ans=0;
	for(int i=1;i<=n;i+=2){
		const int& cc=c[i];
		odd[cc].k++;
		odd[cc].sum_n+=num[i];
		odd[cc].sum_x+=i;
		odd[cc].sum_nx+=num[i]*i;
		odd[cc].sum_n%=MOD;
		odd[cc].sum_x%=MOD;
		odd[cc].sum_nx%=MOD;
	}
	for(int i=2;i<=n;i+=2){
		const int& cc=c[i];
		even[cc].k++;
		even[cc].sum_n+=num[i];
		even[cc].sum_x+=i;
		even[cc].sum_nx+=num[i]*i;
		even[cc].sum_n%=MOD;
		even[cc].sum_x%=MOD;
		even[cc].sum_nx%=MOD;
	}
	for(int i=1;i<=m;i++){
		ans+=odd[i].sum();
		ans+=even[i].sum();
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}