#include<bits/stdc++.h>
using namespace std;
int n,p,t;
int head[40010],tot;
int to[4000110],nxt[4000110];
int vis[40010],mat[40010];
inline void addEd(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
inline void clear(){
	memset(head,0,sizeof(head));
	tot=0;
	memset(mat,0,sizeof(mat));
}
bool dfs(int k){
	for(int i=head[k];i;i=nxt[i]){
		int v=to[i];
		if(!vis[v]){
			vis[v]=1;
			if(!mat[v]||dfs(mat[v])){
				mat[v]=k;
				return true;
			}
		}
	}
	return false;
}
int main(){
	cin>>t;
	while(t--){
		clear();
		int m,x,ans=0;
		cin>>p>>n;
		for(int i=1;i<=p;i++){
			cin>>m;
			for(int j=1;j<=m;j++){
				cin>>x;
				addEd(x,n+i);
				addEd(n+i,x);	
			}
		}
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			if(dfs(i))ans++;
		}
		//cout<<ans<<" ";
		if(ans==p)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
