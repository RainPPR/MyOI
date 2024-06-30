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
const int NR=105;
const int MR=1e4+5;
int price[NR][NR];

int main(){
	int T,n,m;
	scanf("%d%d%d",&T,&n,&m);
	for(int k=1;k<=T;k++){
		for(int i=1;i<=n;i++){
			scanf("%d",&price[k][i]);
		}
	}
	if(T==1){
		printf("%d\n",m);
		return 0;
	}
	return 0;
}