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
int n,m;
int dis[100010];
bool vis[100010];
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
	memset(dis,127,sizeof(dis));
	cin>>n>>m;
	int a,b,c,d;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		if(a==1){
			cin>>d;
			addEd(b,c,-d);
		}
		if(a==2){
			cin>>d;
			addEd(c,b,d);
		}
		if(a==3){
			addEd(b,c,0);
			addEd(c,b,0);
		}
	}
	for(int i=1;i<=n;i++)addEd(n+1,i,0);
	dis[n+1]=0;
	if(SPFA(n+1)){
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
	return 0;
}
