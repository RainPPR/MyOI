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

int main() {
    int n;
    cin>>n;
    string t,ip;
    for(int i=1;i<=n;i++){
        cin>>t>>ip;
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