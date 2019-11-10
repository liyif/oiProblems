#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int t,v;
};
node a[210];
int sum[210];
bool cmp(node x,node y){
	return x.t>y.t;
}
int dp[210][40010];
int ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].v>>a[i].t;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i].v;
	}
	memset(dp,127,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=sum[i];j++){
			if(j>=a[i].v)dp[i][j]=min(dp[i][j],max(dp[i-1][j-a[i].v],j+a[i].t));
			dp[i][j]=min(dp[i][j],max(sum[i]-j+a[i].t,dp[i-1][j]));
		}
	}
	ans=dp[n][0];
	for(int i=1;i<=sum[n];i++)
		ans=min(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}
