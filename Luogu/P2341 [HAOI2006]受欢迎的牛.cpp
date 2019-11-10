#include<bits/stdc++.h>
using namespace std;
int head[10010],tot,cnt,dep;
int to[100010],nxt[100010];
int dfn[10010],low[10010];
int col[10010];
bool vis[10010];
int sum[10010],out[10010];
void addEd(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int n,m;
stack<int>sta;
void tarjan(int k){
	dfn[k]=++dep;
	low[k]=dep;
	vis[k]=1;
	sta.push(k);
	for(int i=head[k];i;i=nxt[i]){
		int u=to[i];
		if(!dfn[u]){
			tarjan(u);
			low[k]=min(low[k],low[u]);
		}
		else if(vis[u]){
			low[k]=min(low[k],dfn[u]);
		}
	}
	if(low[k]==dfn[k]){
		vis[k]=0;
		col[k]=++cnt;
		sum[cnt]++;
		while(sta.top()!=k){
			sum[cnt]++;
			col[sta.top()]=cnt;
			vis[sta.top()]=0;
			sta.pop();
		}
		sta.pop();
	}
}
int main(){
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		addEd(x,y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++)
		for(int j=head[i];j;j=nxt[j]){
			if(col[i]!=col[to[j]])out[col[i]]++;
		}	
	int ans=0,u=0;
	for(int i=1;i<=cnt;i++){
		if(out[i]==0){
			ans=sum[i];
			u++;
		}
	}
	if(u!=1)cout<<0<<endl;
	else cout<<ans<<endl;
	return 0;
}
