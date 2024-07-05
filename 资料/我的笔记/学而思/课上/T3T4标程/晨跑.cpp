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
//m=1 和 S严格递减
//跑1分钟休息1分钟，答案即为S[1]*(n/2)
int S[MR];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&S[i]);
	}
	printf("%d\n",S[1]*(n/2));
	return 0;
}