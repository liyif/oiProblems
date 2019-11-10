#include<bits/stdc++.h>
using namespace std;
int head[20010],tot;
int v[20010],to[20010],nxt[20010];
int dis[20010];
queue<int>que;
bool vis[20010];
int t,c,ts,te;
void addEd(int x,int y,int z){
	v[++tot]=z;
	to[tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
void SPFA(int k){
	memset(dis,127,sizeof(dis));
	dis[k]=0;
	vis[k]=1;
	que.push(k);
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int i=head[u];i;i=nxt[i]){
			int q=to[i];
			if(dis[q]>dis[u]+v[i]){
				dis[q]=dis[u]+v[i];
				if(!vis[q]){
					vis[q]=1;
					que.push(q);
				}
			}
		}
		vis[u]=0;
	}
}
int main(){
	int x,y,z;
	cin>>t>>c>>ts>>te;
	for(int i=1;i<=c;i++){
		cin>>x>>y>>z;
		addEd(x,y,z);
		addEd(y,x,z);
	}
	SPFA(ts);
	cout<<dis[te]<<endl;
	return 0;
}
