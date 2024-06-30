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

int x[MR];
int y[MR];
int cntA[MR],cntB[MR],cntC[MR],cntD[MR];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",x+i);
		y[x[i]]++;
	}

	for(int A=1;A<=n;A++)
	for(int B=A+1;B<=n;B++)
	for(int C=B+1;C<=n;C++)	
	for(int D=C+1;D<=n;D++){
		if(B-A == 2*(D-C) && 3*(B-A)<C-B){
			cntA[A]+=y[B]*y[C]*y[D];
			cntB[B]+=y[A]*y[C]*y[D];
			cntC[C]+=y[A]*y[B]*y[D];
			cntD[D]+=y[A]*y[B]*y[C];
		}

	}

	for(int i=1;i<=m;i++){
		printf("%d %d %d %d\n",cntA[x[i]],cntB[x[i]],cntC[x[i]],cntD[x[i]]);
	}
	return 0;
}