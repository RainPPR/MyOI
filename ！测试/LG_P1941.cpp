#include<iostream>
#include<cstring>
#include<bitset>
using namespace std;

inline int read(){
	int ret=0;
	char ch=' ',c=getchar();
	while(!('0'<=c&&c<='9')) ch=c,c=getchar();
	while('0'<=c&&c<='9') ret=((ret<<1)+(ret<<3)+(c^48)),c=getchar();
	return ch=='-'?-ret:ret;
}
inline int max(int x,int y){ return x>y?x:y; }
inline int min(int x,int y){ return x<y?x:y; }

int n,m,k;
const int N=1e4+10,M=1e3+10,K=1e4+10;
bitset<M> a[N];
int x[N],y[N];
int p[K],l[K],h[K];

int f[2][N];
int g[2][N];
int sum[N];

int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	for(int i=1;i<=k;i++){
		p[i]=read(),l[i]=read(),h[i]=read();
		for(int i=1;i<=l[i];i++) a[p[i]][i]=1;
		for(int i=h[i];i<=m;i++) a[p[i]][i]=1;
		sum[p[i]]++;
	}
	for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
	
	for(int i=1;i<=n;i++){
		memset(f[i&1],0x3f,sizeof(f[i&1]));
		memset(g[i&1],0x3f,sizeof(g[i&1]));
		int mi=0x3f3f3f3f;
		for(int j=1;j<=m;j++){
			if(a[i][j]) continue;
			if(j>x[i]) g[i&1][j]=min(f[i&1^1][j-x[i]]+1,g[i&1][j-x[i]]+1);
			f[i&1][j]=g[i&1][j];
			if(j<=m-y[i]) f[i&1][j]=min(f[i&1^1][j+y[i]],g[i&1][j]);
			mi=min(mi,f[i&1][j]);
		}
		if(mi==0x3f3f3f3f){
			printf("0\n%d",sum[i-1]);
			return 0;
		}
	}
	
	int mi=0x3f3f3f3f;
	for(int j=1;j<=m;j++) mi=min(mi,f[n&1][j]);
	printf("1\n%d",mi);
	return 0;
}
