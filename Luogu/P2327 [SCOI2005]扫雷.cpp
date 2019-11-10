#include<bits/stdc++.h>
using namespace std;
int a[10010];
int n;
int dp[10010][2][2];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		dp[0][0][1]=1;
		dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			dp[i][0][0]=dp[i-1][0][0];
		}
		if(a[i]==1){
			dp[i][0][1]=dp[i-1][0][0];
			dp[i][1][0]=dp[i-1][0][1];
			dp[i][0][0]=dp[i-1][1][0];
		}
		if(a[i]==2){
			dp[i][1][1]=dp[i-1][0][1];
			dp[i][1][0]=dp[i-1][1][1];
			dp[i][0][1]=dp[i-1][1][0];
		}
		if(a[i]==3){
			dp[i][1][1]=dp[i-1][1][1];
		}
	}
	cout<<dp[n][1][0]+dp[n][0][0]<<endl;
	return 0;
}
