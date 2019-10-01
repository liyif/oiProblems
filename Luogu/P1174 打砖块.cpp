#include<bits/stdc++.h>
using namespace std;
int dp[210][210][210];
int p[210][210];
char s[210][210];
int a[210][210];
int b[210][210];
int n,m,k;
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){ 
		for(int j=1;j<=m;j++){
			cin>>p[i][j]>>s[i][j];
		}
	}	
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=k;j>=0;j--){
			for(int v=0;v<=n;v++)
				dp[i][0][j]=max(dp[i][0][j],dp[i-1][v][j]);
			//cout<<dp[i][0][j]<<" ";
		}
		//cout<<endl;
		for(int j=k;j>=0;j--){
			for(int v=1;v<=n;v++)
				if(s[n-v+1][i]=='Y'){
					if(j==0)continue;
					if(v!=1&&dp[i][v-1][j]==0)continue;
					dp[i][v][j]=dp[i][v-1][j]+p[n-v+1][i];
				}
					
				else 
					if(j==k)continue;
					else{
						if(v!=1&&dp[i][v-1][j+1]==0)continue;
						else dp[i][v][j]=dp[i][v-1][j+1]+p[n-v+1][i];
					} 
						
			//cout<<dp[i][1][j]<<" ";
		}
	}
	for(int j=0;j<=k;j++)
	for(int i=0;i<=n;i++)
		ans=max(ans,dp[m][i][j]);
	cout<<ans<<endl;
	return 0;
} 
