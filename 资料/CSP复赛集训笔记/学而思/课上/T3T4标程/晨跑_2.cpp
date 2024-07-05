#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long LL;
const int MR=1e6+10;

int S[MR],sum[MR];
int dis[MR];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&S[i]);
		sum[i]=sum[i-1]+S[i];
	}
	if(n%2) n--;
	n/=2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j<=i){
				dis[i]=max(dis[i],dis[i-j]+sum[j]);
			}
		}
	}
	printf("%d\n",dis[n]);
	return 0;
}