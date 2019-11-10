#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[810][810];
int dp[810][810][18][2];
const int mod=(int)1e9+7;
int main(){
	cin>>n>>m>>k;
	++k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			dp[i][j][a[i][j]%k][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int u=0;u<=k;u++){
				dp[i][j][u][0]=(dp[i][j][u][0]+dp[i-1][j][(u-a[i][j]+k)%k][1])%mod;
				dp[i][j][u][0]=(dp[i][j][u][0]+dp[i][j-1][(u-a[i][j]+k)%k][1])%mod;
				dp[i][j][u][1]=(dp[i][j][u][1]+dp[i-1][j][(u+a[i][j])%k][0])%mod;
				dp[i][j][u][1]=(dp[i][j][u][1]+dp[i][j-1][(u+a[i][j])%k][0])%mod;
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=(ans+dp[i][j][0][1])%mod;
	cout<<ans<<endl;
	return 0;
}
