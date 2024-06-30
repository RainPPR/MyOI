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
const int MR=1e5+10;
int a[MR],b[MR];//a红队b蓝队
int c[MR];//c[i]表示红队第i名与蓝队第c[i]名比赛

int n,maxscore,minscore;
int v[MR];
void dfs(int p){
    if(p>n){
        int score=0;
        for(int i=1;i<=n;i++){
            if(a[i]>b[c[i]]) score+=2;
            else if(a[i]==b[c[i]]) score+=1;
        }
        maxscore=max(maxscore,score);
        minscore=min(minscore,score);
        return;
    }
    for(int i=1;i<=n;i++){
        if(v[i]) continue;
        v[i]=1;
        c[p]=i;
        dfs(p+1);
        v[i]=0;
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    maxscore=0;minscore=2*n;
    dfs(1);
    printf("%d %d\n",maxscore,minscore);
    return 0;
}