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
int n,a[MR];
map<int,int> mymap;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    mymap[a[1]]=1;
    for(int i=2;i<=n;i++){
        map<int,int>::iterator it;
        it=mymap.upper_bound(a[i]);
        int d1=1e9,d2=1e9,i1,i2;
        if(it!=mymap.end()){
            d1=it->first - a[i];
            i1=it->second;
        }
        if(it!=mymap.begin()){
            --it;
            d2=a[i] - it->first;
            i2=it->second;
        }
        if(d1<d2) printf("%d %d\n",a[i1]-a[i],i1);
        else printf("%d %d\n",a[i]-a[i2],i2);
        mymap[a[i]]=i;
    }
    return 0;
}