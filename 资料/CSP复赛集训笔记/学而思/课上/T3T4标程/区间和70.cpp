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
int n,m;
map<int,int> a;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x,c;
        scanf("%d%d",&x,&c);
        a[x]+=c;
    }
    for(int i=1;i<=m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        map<int,int>::iterator Lit,Rit;
        Lit=a.lower_bound(l);
        Rit=a.upper_bound(r);
        LL sum=0;
        for(map<int,int>::iterator it=Lit;it!=Rit;++it){
            sum+=it->second;
        }
        printf("%lld\n",sum);
    }

    return 0;
}