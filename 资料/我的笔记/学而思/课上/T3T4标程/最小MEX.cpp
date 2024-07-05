#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<ctime>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long LL;
const int MR=1.5e6+10;
int n,m,a;
int pos[MR],nxt[MR],h[MR],cnt;
void add(int x,int i){//有一个值为x的值出现在下标i
    cnt++;
    pos[cnt]=i;
    nxt[cnt]=h[x];
    h[x]=cnt;
}
bool check(int x){
    for(int i=h[x];nxt[i]!=0;i=nxt[i]){
        if(pos[i]-pos[nxt[i]]>m){
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++) add(i,0);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        add(a,i);
    }
    for(int i=0;i<=n;i++) add(i,n+1);
    for(int i=0;i<=n;i++){
        if(check(i)){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}