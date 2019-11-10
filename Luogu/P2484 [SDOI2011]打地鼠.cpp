#include<bits/stdc++.h>
using namespace std;
int m,n,r,c;
int a[110][110],b[110][110];
int sum;
int ans=999999999;
bool check(){
	if(sum%(r*c)!=0)return false;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			b[i][j]=a[i][j]-a[i][j-1];
	for(int i=1;i<=m-r+1;i++)
		for(int j=1;j<=n-c+1;j++){
			if(b[i][j]!=0){
				if(b[i][j]<0)return false;
				for(int k=r-1;k>=0;k--){
					b[i+k][j+c]+=b[i][j];
					b[i+k][j]-=b[i][j];
				}
			}
		}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(b[i][j]!=0)return false;
	return true;
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			sum+=a[i][j];
		}
	for(r=1;r<=m;r++)
		for(c=1;c<=n;c++){
			if(check()){
				ans=min(ans,sum/r/c);
			}
		}
	cout<<ans<<endl;
	return 0;
}
