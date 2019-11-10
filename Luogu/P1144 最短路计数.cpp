#include<bits/stdc++.h>
using namespace std;
int n,m;
queue<int>que;
int head[10000010],tot;
int to[20000010],nxt[20000010];
void addEd(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int dis[10000010],vis[10000010];
int ans[10000010];
void bfs(int k){
	dis[k]=0;
	vis[k]=1;
	ans[k]=1;
	que.push(k);
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(!vis[v]){
				dis[v]=dis[u]+1;
				vis[v]=1;
				que.push(v);
			}	
			if(dis[v]==dis[u]+1){
				ans[v]=(ans[v]+ans[u])%100003;
			}
		}
	}
}
int main(){
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		addEd(x,y);
		addEd(y,x);
	}
	bfs(1);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	return 0;
}
