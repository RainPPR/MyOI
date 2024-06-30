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
const int MR=1e5+10;
const int INF=0x3f3f3f3f;
int n,m;
map<int,int> a;
map<int,int> idx;//存每个坐标的大小顺序
LL s[MR];//前缀和
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x,c;
        scanf("%d%d",&x,&c);
        a[x]+=c;
    }
    a[-INF]=0;
    a[INF]=0;
    int cnt=0;
    for(auto p:a){
        cnt++;
        idx[p.first]=cnt;
        s[cnt]=s[cnt-1]+p.second;
    }
    for(int i=1;i<=m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        map<int,int>::iterator Lit,Rit;
        Lit=a.lower_bound(l);
        Rit=a.upper_bound(r);
        int L=idx[Lit->first]-1,R=idx[Rit->first]-1;
        //printf("L=%d R=%d\n",L,R);
        LL sum=0;
        sum=s[R]-s[L];
        printf("%lld\n",sum);
    }

    return 0;
}