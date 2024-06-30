main(){
int n,k,s;scanf("%d%d%d",&n,&k,&s);
for(int i=0;i<k;++i)printf("%d ",s);
if(s==1e9)for(int i=k;i<n;++i)printf("1 ");
else for(int i=k;i<n;++i)printf("1000000000 ");
}