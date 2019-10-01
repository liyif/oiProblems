#include<bits/stdc++.h>
using namespace std;
struct node{
	int next;
	int to;
	int v;
}edge[100100];
int tot;
int head[110];
int n,a,b;
int dis[110];
struct ns{
	int x,y;
	ns(int cx,int cy):x(cx),y(cy){
	}
}; 
bool operator>(const ns& l,const ns& r){
	return l.y>r.y;
}
priority_queue<ns,deque<ns>,greater<ns> > que;
void addEdge(int x,int y,int v){
	edge[++tot].to=y;
	edge[tot].v=v;
	edge[tot].next=head[x];
	head[x]=tot;
}
int main(){
	memset(dis,-1,sizeof(dis));
	cin>>n>>a>>b;
	int x,u;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x!=0){
			cin>>u;
			addEdge(i,u,0);
			for(int j=1;j<x;j++){
				cin>>u;
				addEdge(i,u,1);
			}
		}
	}
	que.push(ns(a,0));
	while(!que.empty()){
		int x=que.top().x;
		int y=que.top().y;
		que.pop();
		if(dis[x]!=-1)continue;
		dis[x]=y;
		if(x==b){
			break;
		}
		for(int i=head[x];i!=0;i=edge[i].next){
			que.push(ns(edge[i].to,y+edge[i].v));
		}
	}
	cout<<dis[b]<<endl;
	return 0;
} 
