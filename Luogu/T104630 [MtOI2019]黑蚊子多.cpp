#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int f[1010];
int main(){
	cin>>n>>m>>k;
	int x;
	for(int i=1;i<=k;i++){
		cin>>x;
		f[x]=1;
	}
	int v=0,ans=0;
	while(v<n){
		m+=f[v];
		ans++;
		v+=m;
	}
	cout<<ans<<endl;
	return 0;
}
