#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,val,next;
}; 
node edge[400010];
int head[5010];
int dis[5010];
bool vis[5010]; 
int n,m;
int tot;
int ans; 
void addedge(int x,int y,int z){
	edge[tot].to=y;
	edge[tot].val=z;
	edge[tot].next=head[x];
	head[x]=tot++;
}
using Pair=pair<int,int>;
priority_queue<Pair,deque<Pair>,greater<Pair> > que;
voi prim(){
	dis[1]=0; 
	que.push(make_pair(0,1));
	int cnt=0;
	while(!que.empty()&&cnt<n){
		Pair x=que.top();
		que.pop();
		if(vis[x.second])continue;
		cnt++;
		ans+=x.first;
		vis[x.second]=1; 
		for(int i=head[x.second];i!=-1;i=edge[i].next){
			if(edge[i].val<dis[edge[i].to]){
				dis[edge[i].to]=edge[i].val;
				que.push(make_pair(dis[edge[i].to],edge[i].to));
			}
		}
	}
}
int main(){
	memset(head,-1,sizeof(head));
	memset(dis,127,sizeof(dis));
	cin>>n>>m;
	int x,y,z;
	for(int i=0;i<m;i++){
		cin>>x>>y>>z;
		addedge(x,y,z);
		addedge(y,x,z);
	}
	prim();
	cout<<ans<<endl;
	return 0;
}

