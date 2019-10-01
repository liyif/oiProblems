#include<bits/stdc++.h>
using namespace std;
struct Lgint {
    short s[510];
    int size;
    Lgint() {
        size=0;
        memset(s,0,sizeof(s));
    }
    Lgint(int x) {
        size=0;
        memset(s,0,sizeof(s));
        while(x!=0) {
            s[size++]=x%10;
            x/=10;
        }
    }
    void print() {
        for(int i=size-1; i>=0; --i)
            printf("%d",s[i]);
        if(size==0)printf("0");
    }
};
Lgint operator+(Lgint lq,const Lgint &rq) {
    int len=max(lq.size,rq.size);
    for(int i=0; i<len; ++i) {
        lq.s[i]+=rq.s[i];
        lq.s[i+1]+=lq.s[i]/10;
        lq.s[i]%=10;
    }
    lq.size=len;
    if(lq.s[len]!=0)++lq.size;
    return lq;
}
Lgint operator*(Lgint lq,const int &rq) {
    int i=0;
    int x=0;
    while(i<lq.size||x!=0) {
        lq.s[i]*=rq;
        lq.s[i]+=x;
        x=lq.s[i]/10;
        lq.s[i]%=10;
        ++i;
    }
    lq.size=i;
    return lq;
}
bool operator<(const Lgint& lq,const Lgint& rq) {
    if(lq.size<rq.size)return true;
    if(rq.size<lq.size)return false;
    for(int i=lq.size-1; i>=0; --i)
        if(lq.s[i]<rq.s[i])return true;
    return false;
}
int n,m;
int a[90];
Lgint bz[90];
Lgint dp[90][90], ans;
void bzt() {
    bz[0]=1;
    for(int i=1; i<=m+2; i++)
        bz[i]=bz[i-1]*2;
}
int main() {
    cin>>n>>m;
    bzt();
    while(n--) {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=m; i++)
            cin>>a[i];
        for(int i=1; i<=m; i++)
            for(int j=m; j>=i; j--) {
                dp[i][j]=max(dp[i][j],dp[i-1][j]+bz[m-j+i-1]*a[i-1]);
                dp[i][j]=max(dp[i][j],dp[i][j+1]+bz[m-j+i-1]*a[j+1]);
            }
        Lgint maxn;
        for(int i=1; i<=m; i++)
            maxn=max(maxn,dp[i][i]+bz[m]*a[i]);
        ans=ans+maxn;
        ans.print();
        cerr<<endl;
    }
    ans.print();
    return 0;
}
