#include<bits/stdc++.h>
using namespace std;
bool stone[500010];
int a[10010];
int b[10010];
int dp[500010];
int l,s,t,m;
int main(){
	cin>>l>>s>>t>>m;
	memset(dp,0x7f,sizeof(dp));
	dp[0]=0;
	int x;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++){
		b[i]=(a[i]-a[i-1])%2520;
	}
	for(int i=1;i<=m;i++){
		a[i]=a[i-1]+b[i];
		stone[a[i]]=1;
	}
	l=a[m];
	for(int i=1;i<=l+t;i++){
		for(int j=s;j<=t;j++){
			if(i-j>=0)
				dp[i]=min(dp[i],dp[i-j]);
			dp[i]+=stone[i];
		}
	}
	int ans=dp[l];
	for(int i=l+1;i<=l+t;i++)
		ans=min(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}
