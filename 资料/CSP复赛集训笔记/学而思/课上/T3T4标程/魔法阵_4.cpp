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
const int NR=2e4+10;
int x[MR];
int y[NR];//y[x]表示魔法值为x的物品个数
int syk[NR],sy2k[NR];
//syk是y[i]*y[i+k]的前缀和,sy2k是y[i]*y[i+2*k]的前缀和
int cntA[MR],cntB[MR],cntC[MR],cntD[MR];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",x+i);
		y[x[i]]++;
	}
	int kcap=(n-1)/9;

	for(int k=1;k<=kcap;k++){
		for(int i=1;i<=n;i++){
			syk[i]=syk[i-1]+y[i]*y[i+k];
			sy2k[i]=sy2k[i-1]+y[i]*y[i+2*k];
		}
		for(int A=1;A+9*k<n;A++){
			cntA[A] += y[A+2*k]*(syk[n]-syk[A+8*k]);
			cntB[A+2*k] += y[A]*(syk[n]-syk[A+8*k]);
		}

		for(int C=8*k+2;C+k<=n;C++){
			cntC[C] += y[C+k]*sy2k[C-8*k-1];
			cntD[C+k] += y[C]*sy2k[C-8*k-1];
		}

	}



	for(int i=1;i<=m;i++){
		printf("%d %d %d %d\n",cntA[x[i]],cntB[x[i]],cntC[x[i]],cntD[x[i]]);
	}
	return 0;
}