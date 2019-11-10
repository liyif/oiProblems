#include<bits/stdc++.h>
using namespace std;
int head[40010],tot;
int to[80010],nxt[80010];
int dis[40010][3];
int b,e,p,n,m;
void addEd(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
queue<int> que;
void bfs(int k,int s){
	dis[k][s]=1;
	que.push(k);
	while(!que.empty()){
		int x=que.front();
		que.pop();
		for(int i=head[x];i;i=nxt[i]){
			if(!dis[to[i]][s]){
				dis[to[i]][s]=dis[x][s]+1;
				que.push(to[i]);
			}
		}
	}
}
long long ans=1e9;
int main(){
	cin>>b>>e>>p>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		addEd(x,y);
		addEd(y,x);
	}
	bfs(1,0);
	bfs(2,1);
	if(p<=b+e){bfs(n,2);
	for(int i=1;i<=n;i++){
		ans=min(ans,(long long)(dis[i][0]-1)*b+(dis[i][1]-1)*e+(dis[i][2]-1)*p);
	}}
	else {
		ans=(dis[n][0]-1)*b+(dis[n][1]-1)*e;
	}
	cout<<ans<<endl;
	return 0;
}
