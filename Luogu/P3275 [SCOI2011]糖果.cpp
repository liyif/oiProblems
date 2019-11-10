#include<bits/stdc++.h>
using namespace std;
int val[200010],to[200010],nxt[200010];
int head[100010],tot;
//100000
void addEd(int l,int r,int v){
	val[++tot]=v;
	to[tot]=r;
	nxt[tot]=head[l];
	head[l]=tot;
}
int n,m,w;
int dis[101000];
int vis[101000];
bool SPFA(int k){
	vis[k]=1;
	for(int i=head[k];i;i=nxt[i]){
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
	int x,a,b;
	for(int i=1;i<=m;i++){
		cin>>x>>a>>b;
		switch(x){
			case 1:addEd(a,b,0);addEd(b,a,0);break;
			case 2:addEd(b,a,-1);break;
			case 3:addEd(a,b,0);break;
			case 4:addEd(a,b,-1);break;
			case 5:addEd(b,a,0);break;
		}
	}
	for(int i=1;i<=n;i++)addEd(n+1,i,0);
	dis[n+1]=1;
	if(!SPFA(n+1)){
		cout<<-1<<endl;
	}
	else {
		long long sum=0;
		int minn=dis[1];
		for(int i=1;i<=n;i++){
			minn=min(minn,dis[i]);
		}
		for(int i=1;i<=n;i++){
			sum+=dis[i]-minn+1;
		}
		cout<<sum<<endl;
	}
	return 0;
}
