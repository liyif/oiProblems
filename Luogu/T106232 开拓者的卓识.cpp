#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100010];
long long num[100010];
const int mod=998244353;
int var[1002][10001];
int sum(const int &k,const int &l,const int &r){
	if(k==1)return (num[r]-num[l-1])%mod;
	int ans=0;
	if(l==1&&r<10001&&var[k][r]!=-1)return var[k][r];
	for(int i=l;i<=r;i++)
		for(int j=i;j<=r;j++)
			ans=(ans+sum(k-1,i,j))%mod;
	if(l==1&&r<10001)var[k][r]=ans;
	return ans;
}
void read(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int main(){
	memset(var,-1,sizeof(var));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		read(a[i]);
		num[i]=(num[i-1]+a[i]);
	}
	for(int i=1;i<=n;i++){
		cout<<sum(k,1,i)<<" ";
	}
	return 0;
}
