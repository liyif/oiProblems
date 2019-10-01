#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,next,v;
};
node edge[200010];
int head[100010],tot;
int n,m,k,p,t;
void addEd(int x,int y,int v){
	edge[++tot].to=y;
	edge[tot].v=v;
	edge[tot].next=head[x];
	head[x]=tot;
	//cerr<<x<<" "<<tot<<" "<<head[x]<<endl;
}
struct koishi{
	int id;
	int v;
	koishi(int ci,int cv):id(ci),v(cv){
	}
};
inline bool operator>(const koishi &l,const koishi &r){
	return l.v>r.v;
}
int disp[100010];
void dis(){
	priority_queue<koishi,deque<koishi>,greater<koishi> >que; 
	memset(disp,-1,sizeof(disp));
	que.push(koishi(1,0));
	while(!que.empty()){
		koishi g=que.top();
		que.pop();
		//if(disp[g.id]==g.v&&disp[g.id]!=-1)return true;
		if(disp[g.id]!=-1)continue;
		disp[g.id]=g.v;
		for(int i=head[g.id];i!=0;i=edge[i].next){
			if(disp[edge[i].to]==-1)
				que.push(koishi(edge[i].to,g.v+edge[i].v));
		}
	}
}
int ans;
int u[100010];
bool r;
void dfs(int z,int sum){
	if(r)return;
	if(sum>disp[z]+k)return;
	if(u[z]==sum){
		r=1;
		return;
	}
	int o=u[z];
	u[z]=sum;
	if(z==n){
		ans=(ans+1)%p;
	}
	for(int i=head[z];i!=0;i=edge[i].next){
		dfs(edge[i].to,sum+edge[i].v);
	}
	u[z]=o;
}
int main(){
	cin>>t;
	while(t--){
		memset(head,0,sizeof(head));
		tot=0;
		ans=0;
		r=0;
		cin>>n>>m>>k>>p;
		int x,y,z;
		for(int i=1;i<=m;++i){
			cin>>x>>y>>z;
			addEd(x,y,z);
		}
		dis();
		memset(u,-1,sizeof(u));
		dfs(1,0);
		if(r)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
} 
