#include<bits/stdc++.h>
using namespace std;
int T,n,q,x,y,z,fa[100010],a[100010],num,dfn[200010],rk[200010],cnt[100010],s[1010],ans[100010],fg[100010];
vector<pair<int,int> >E[100010];
struct query
{
    int l,r,id;
    friend bool operator <(const query &a,const query &b)
    {
        return a.l/T^b.l/T?a.l/T<b.l/T:(a.l/T&1?a.r<b.r:a.r>b.r);
    }
}Q[100010];
void dfs(int x)
{
    dfn[x]=++num;
    rk[num]=x;
    for(pair<int,int>i:E[x])
    {
        int y=i.first,z=i.second;
        if(y!=fa[x])
        {
            fa[y]=x;
            a[y]=z;
            dfs(y);
        }
    }
    rk[++num]=x;
}
inline void update(int x)
{
    if(a[x]>n)
        return;
    if(fg[x]^=1)
    {
        if(!(cnt[a[x]]++))
            s[a[x]/T]++;
    }
    else
        if(!(--cnt[a[x]]))
            s[a[x]/T]--;    
} 
int main()
{
    scanf("%d%d",&n,&q);
    T=sqrt(n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        E[x].push_back({y,z});
        E[y].push_back({x,z});
    }
    dfs(1);
    a[1]=n+1;
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        if(dfn[x]>dfn[y])
            swap(x,y);
        Q[i]={dfn[x],dfn[y],i};
    }
    sort(Q+1,Q+q+1);
    for(int i=1,L=1,R=1;i<=q;i++)
    {
        while(R<Q[i].r)
            update(rk[++R]);
        while(L>Q[i].l)
            update(rk[L--]);
        while(R>Q[i].r)
            update(rk[R--]);
        while(L<Q[i].l)
            update(rk[++L]);
        for(int j=0;;j++)
            if(s[j]<T)
            {
                for(int k=j*T;;k++)
                    if(!cnt[k])
                    {
                        ans[Q[i].id]=k;
                        break;
                    } 
                break;
            }
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
    return 0;
}