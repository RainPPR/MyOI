#include<bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
const int maxn=1e5+26,sz=317,sqn=326,mx=1e5;
struct Data{
    int val,id;
}a[maxn];
int n,m,L,R;
ll ans;
inline int lowbit(int x){
    return x&-x;
}
namespace Sherry_BiTre{
    int T[maxn];
    inline void Modify(int p,int val){
        while(p<=n){
            T[p]+=val;
            p+=lowbit(p);
        }
        return ;
    }
    inline int Query(int p){
        int res=0;
        while(p){
            res+=T[p];
            p-=lowbit(p);
        }
        return res;
    }
}
using namespace Sherry_BiTre;
namespace Sherry_Block{
    int bcnt,bl[maxn],l[sqn],r[sqn],aa[sqn][sqn],b[sqn][sqn],d[sqn][maxn];
    ll c[sqn][sqn];
    int aaa[sqn],topa,bbb[sqn],topb,res;
    inline int Gb(int bll,int lL,int lR,int blr,int rL,int rR){
        topa=topb=res=0;
        for(int i=l[bll];i<=r[bll];i++)
            if(lL<=a[i].id&&a[i].id<=lR)
                aaa[++topa]=a[i].val;
        for(int i=l[blr];i<=r[blr];i++)
            if(rL<=a[i].id&&a[i].id<=rR)
                bbb[++topb]=a[i].val;
        int i,j;
        i=j=1;
        while(i<=topa&&j<=topb){
            if(aaa[i]<bbb[j])
                i++;
            else{
                j++;
                res+=topa-i+1;
            }
        }
        return res;
    }
    inline void Init(){
        bcnt=(n-1)/sz+1;
        for(int i=1;i<=bcnt;i++){
            l[i]=r[i-1]+1;
            r[i]=r[i-1]+sz;
            if(i==bcnt)
                r[i]=n;
            for(int j=l[i];j<=r[i];j++){
                a[j].id=j-l[i]+1;
                aa[i][j-l[i]+1]=aa[i][j-l[i]]+j-l[i]-Query(a[j].val);
                Modify(a[j].val,1);
            }
            b[i][r[i]-l[i]+1]=aa[i][r[i]-l[i]+1];
            Modify(a[l[i]].val,-1);
            for(int j=l[i]+1;j<=r[i];j++){
                b[i][r[i]-j+1]=b[i][r[i]-j+2]-Query(a[j].val)+1;
                Modify(a[j].val,-1);
            }
            sort(a+l[i],a+r[i]+1,[](Data xy,Data zb){
                return xy.val<zb.val;
            });
            for(int j=l[i];j<=r[i];j++){
                bl[j]=i;
                d[i][a[j].val-1]++;
            }
            for(int j=mx;j>=0;j--)
                d[i][j]+=d[i][j+1];
        }
        for(int i=2;i<=bcnt;i++)
            for(int j=0;j<=mx;j++)
                d[i][j]+=d[i-1][j];
        for(int i=1;i<bcnt;i++)
            for(int j=i+1;j<=bcnt;j++)
                c[i][j]=Gb(i,1,sz,j,1,r[j]-l[j]+1);
        for(int i=1;i<=bcnt;i++)
            for(int j=1;j<=bcnt;j++)
                c[i][j]+=c[i-1][j]+c[i][j-1]-c[i-1][j-1];
        return ;
    }
}
using namespace Sherry_Block;
inline ll C(int L,int R){
    if(R<L)
        return 0;
    return c[R][R]-c[L][L-1]-c[L-1][L]+c[L-1][L-1];
}
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i].val);
    Init();
    while(m--){
        scanf("%lld%lld",&L,&R);
        L^=ans;
        R^=ans;
        if(bl[L]==bl[R])
            ans=aa[bl[R]][R-l[bl[R]]+1]-aa[bl[L]][L-l[bl[L]]]-Gb(bl[L],1,L-l[bl[L]],bl[R],L-l[bl[L]]+1,R-l[bl[R]]+1);
        else{
            ans=b[bl[L]][r[bl[L]]-L+1]+aa[bl[R]][R-l[bl[R]]+1]+C(bl[L]+1,bl[R]-1)+Gb(bl[L],L-l[bl[L]]+1,sz,bl[R],1,R-l[bl[R]]+1);
            for(int i=bl[L]+1;i<bl[R];i++)
                ans+=aa[i][sz];
            for(int i=L;i<=r[bl[L]];i++)
                ans+=l[bl[R]]-1-r[bl[L]]-d[bl[R]-1][a[i].val]+d[bl[L]][a[i].val];
            for(int i=l[bl[R]];i<=R;i++)
                ans+=d[bl[R]-1][a[i].val]-d[bl[L]][a[i].val];
        }
        printf("%lld\n",ans);
    }
    return 0;
}