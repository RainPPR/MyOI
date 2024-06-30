#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int MR=1e3+10;
typedef long long LL;
map<string,int> s;//记录每个server的编号
//计算字符s[l]到s[r]构成的数字
int num(string& s,int l,int r){
    if(l>r) return -1;
    if(r-l>=5) return -1;
    if(s[l]=='0' && l<r) return -1;
    int x=0;
    for(int i=l;i<=r;i++){
        if('0'<=s[i] && s[i]<='9'){
            x=x*10+(s[i]-'0');
        }
        else return -1;
    }
    return x;
}

bool isLegal(string& s){
    int id[6]={};//点的位置
    int i,cur=0;
    for(i=0;i<s.size();i++){
        if(s[i]=='.'){
            cur++;
            id[cur]=i;
        }
        if(cur==3) break;
    }
    if(cur!=3) return false;
    for(;i<s.size();i++){
        if(s[i]==':'){
            cur++;
            id[cur]=i;
            break;
        }
    }
    int a=num(s,0,id[1]-1);
    int b=num(s,id[1]+1,id[2]-1);
    int c=num(s,id[2]+1,id[3]-1);
    int d=num(s,id[3]+1,id[4]-1);
    int e=num(s,id[4]+1,s.size()-1);
    if(a<0 || a>255) return false;
    if(b<0 || b>255) return false;
    if(c<0 || c>255) return false;
    if(d<0 || d>255) return false;
    if(e<0 || e>65535) return false;
    return true;
}
int main() {
    int n;
    cin>>n;
    string t,ip;
    for(int i=1;i<=n;i++){
        cin>>t>>ip;
        if(!isLegal(ip)){
            printf("ERR\n");
            continue;
        }
        if(t=="Server"){
            if(s.count(ip)){
                printf("FAIL\n");
            }
            else{
                s[ip]=i;
                printf("OK\n");
            }
        }
        else if(t=="Client"){
            if(s.count(ip)){
                printf("%d\n",s[ip]);
            }
            else{
                printf("FAIL\n");
            }
        }
    }
    return 0;
}