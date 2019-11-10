#include<bits/stdc++.h>
using namespace std;
int val[100010],to[100010],nxt[100010];
int head[100010],tot;
void addEd(int l,int r,int v){
	val[++tot]=v;
	to[tot]=r;
	nxt[tot]=head[l];
	head[l]=tot;
}
int n,m,w;
int dis[10100];
int vis[10100];
bool SPFA(int k){
	vis[k]=1;
	for(int i=head[k];i;i=nxt[i]){
		//cout<<k<<" "<<to[i]<<" "<<dis[to[i]]<<endl;
		if(dis[to[i]]>dis[k]+val[i]){
			dis[to[i]]=dis[k]+val[i];
			if(vis[to[i]])return false;
			if(!SPFA(to[i]))return false;
		}
	}
	vis[k]=0;
	return true;
}
int main(){
	cin>>w;
	while(w--){
		tot=0;
		memset(head,0,sizeof(dis));
		memset(dis,127,sizeof(dis));
		memset(vis,0,sizeof(vis));
		cin>>n>>m;
		int s,t,v;
		for(int i=1;i<=m;i++){
			cin>>s>>t>>v;
			//cout<<s-1<<" "<<t<<endl; 
			addEd(s-1,t,v);
			addEd(t,s-1,-v);
		}
		for(int i=0;i<=n;i++)addEd(n+1,i,0);
		dis[n+1]=0;
		if(SPFA(n+1))cout<<"true"<<endl;
		else cout<<"false"<<endl;
	}
	return 0;
}
