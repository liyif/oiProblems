#include<bits/stdc++.h>
using namespace std;
int head[310],tot;
int to[1210],v[1210],nxt[1210];
void addEd(int x,int y,int z){
	to[++tot]=y;
	v[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}
int vis[310];
int dis[310];
int ris[310];
int d,p,c,f;
queue<int> que;
bool SPFA(int k){
	vis[k]=1;
	dis[k]=0;
	que.push(k);
	while(!que.empty()){
		int x=que.front();
		que.pop();
		vis[x]=0;
		ris[x]++;
		if(ris[x]>c)return 0;
		for(int i=head[x];i;i=nxt[i]){
			int u=to[i];
			if(dis[x]+v[i]>dis[u]){
				dis[u]=dis[x]+v[i];
				if(!vis[u])
					que.push(u);
			}
		}
	}
	return true;
}
int main(){
	memset(dis,-1,sizeof(dis));
	cin>>d>>p>>c>>f;
	int x,y,z;
	for(int i=1;i<=p;i++){
		cin>>x>>y;
		addEd(x,y,d);
	}
	for(int i=1;i<=f;i++){
		cin>>x>>y>>z;
		addEd(x,y,d-z);
	}
	for(int i=1;i<=c;i++){
		addEd(c+1,i,d);
	}
	if(!SPFA(c+1))cout<<"orz"<<endl;
	else {
		int ans=0;
		for(int i=1;i<=c;i++)
			ans=max(ans,dis[i]);
		cout<<ans<<endl;
	}
	return 0;
}
