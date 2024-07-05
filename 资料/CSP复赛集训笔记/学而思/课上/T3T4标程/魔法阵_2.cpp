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
const int MR=5e4+10;

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
	for(int A=1;A<=n-3;A++){

		for(int D=A+3;D<=n;D++){

			for(int C=(A+8*D)/9+1;C<=D-1;C++){

				int B=A+2*D-2*C;
				cntA[A]+=y[B]*y[C]*y[D];
				cntB[B]+=y[A]*y[C]*y[D];
				cntC[C]+=y[A]*y[B]*y[D];
				cntD[D]+=y[A]*y[B]*y[C];
			}
		}
	}

	for(int i=1;i<=m;i++){
		printf("%d %d %d %d\n",cntA[x[i]],cntB[x[i]],cntC[x[i]],cntD[x[i]]);
	}
	return 0;
}