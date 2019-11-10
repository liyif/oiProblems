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
int n,h;
int dis[100010];
bool vis[100010];
queue<int> que;
int SPFA(int k){
	que.push(k);
	memset(dis,127,sizeof(dis));
	dis[k]=0;
	vis[k]=1;
	while(!que.empty()){
		int s=que.front();
		que.pop();
		vis[s]=0;
		for(int i=head[s];i;i=nxt[i]){
			if(dis[s]+val[i]<dis[to[i]]){
				dis[to[i]]=dis[s]+val[i];
				if(!vis[to[i]]){
					vis[to[i]]=1;
					que.push(to[i]);
				}		
			}	
		}
	}
}
int main(){
	cin>>n>>h;
	int b,e,t;
	for(int i=1;i<=h;i++){
		cin>>b>>e>>t;
		addEd(e,b-1,-t);
	}
	for(int i=1;i<=n;i++){
		addEd(i-1,i,1);
		addEd(i,i-1,0);
	}
	for(int i=0;i<=n;i++)addEd(n+1,i,0);
	SPFA(n+1);
	int minn=1e9;
	for(int i=0;i<=n;i++){
		minn=min(minn,dis[i]);
	}
	cout<<dis[n]-minn<<endl;
	return 0;
} 
