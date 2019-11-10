#include<bits/stdc++.h>
using namespace std;
int head[20010],tot,cnt,dep;
int to[200010],nxt[200010];
int dfn[20010],low[20010];
bool fla[20010];
void addEd(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int n,m;
void tarjan(int k,int fa){
	dfn[k]=low[k]=++dep;
	int cld=0;
	for(int i=head[k];i;i=nxt[i]){
		int u=to[i];
		if(!dfn[u]){
			tarjan(u,k);
			low[k]=min(low[k],low[u]);
			if(low[u]>=dfn[k]&&k!=fa){
				fla[k]=1;
			}
			if(k==fa)cld++;
		}
		low[k]=min(low[k],dfn[u]);
	}
	if(cld>=2&&k==fa)fla[k]=1;
}
int main(){
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		addEd(x,y);
		addEd(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i,i);
	int sum=0;
	for(int i=1;i<=n;i++)
		if(fla[i])sum++;
	cout<<sum<<endl;
	for(int i=1;i<=n;i++)
		if(fla[i])cout<<i<<" ";
	return 0;
}
