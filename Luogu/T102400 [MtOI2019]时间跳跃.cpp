#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
long long ksm(long long x,long long y) {
	long long ans=1;
	while(y) {
		if(y&1) ans=ans*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ans;
}
int gm(long long x,long long y) {
	return x*ksm(y,mod-2)%mod;
}
int t;
int n;
long long c[5010][5010];
long long gec(int x,int y) {
	if(c[x][y]!=0)return c[x][y];
	if(y==0)return 1;
	if(x==0)return 0;
	c[x][y]=gec(x-1,y-1)+gec(x-1,y);
	return c[x][y];
}
long long c3;
int a;
int main() {
	cin>>t;
	while(t--) {


		cin>>a;
		long long ans=0,bk=0;
		c3=0;
		for(int i=1; i<=a-2; i++) {
			for(int j=i+1; j<=a-1; j++)
			//	c3+=min(i+j,a+1)-j-1;
			for(int k=j+1;k<i+j&&k<=a;k++)
			c3++;
		}
		for(int i=0; i<=a; i++)
			bk+=gec(a,i);
		for(int i=4; i<=a; i++)
			ans+=gec(a,i)*i;
		cout<<gm(ans+c3*3,bk)<<endl;
	}
	return 0;
}
