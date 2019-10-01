#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[510];
int a[510];
int dp[4000010];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	t[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]>2*m)t[i]=t[i-1]+2*m;
		else t[i]=t[i-1]+a[i]-a[i-1];
	}
	int v=0;
	memset(dp,127,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<m;i++){
		int ans=0;
		for(int k=1;k<=n&&t[k]<i;k++){
			ans+=i-t[k];
		}
		dp[i]=ans;
		//cout<<dp[i]<<" ";
	}
	for(int i=m;i<t[n]+m;i++){
		int s=i-m-m;
		if(s<0)s=0;
		int ans=0,k=n;
		while(k>0&&t[k]>=i)k--;
		for(int j=i-m;j>=s;j--){
			//++v;
			while(k>0&&t[k]>j){
				ans+=i-t[k];
				k--;
			}
			dp[i]=min(dp[i],dp[j]+ans);
		}
		//cout<<dp[i]<<" ";
	}
	int ans=100000000;
	for(int i=t[n];i<t[n]+m;i++)
		ans=min(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}
