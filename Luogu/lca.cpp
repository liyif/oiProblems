#include<bits/stdc++.h>
using namespace std;
int head[1000010],tot;
int to[2000010],nxt[2000010];
void addEd(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int n,m,s;
int lg[1000010];
int f[23][1000010],dpth[1000010];
void DFS(int k,int v){
	f[0][k]=v,dpth[k]=dpth[v]+1;
	for(int i=1;(1<<i)<dpth[k];i++)
		f[i][k]=f[i-1][f[i-1][k]];
	for(int i=head[k];i;i=nxt[i])
		if(to[i]!=v)DFS(to[i],k);
}
int lca(int x,int y){
	if(dpth[x]<dpth[y])swap(x,y);
	while(dpth[x]>dpth[y])x=f[lg[dpth[x]-dpth[y]]-1][x];
	if(x==y)return x;
	for(int i=lg[dpth[x]]-1;i>=0;i--){
		if(f[i][x]!=f[i][y])
			x=f[i][x],y=f[i][y];
	}
	return f[0][x];
}
int main(){
	cin>>n>>m>>s;
	int x,y;
	for(int i=1;i<=n-1;i++){
		cin>>x>>y;
		addEd(x,y);
		addEd(y,x);
	}
	for(int i=1;i<=n;i++)
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	DFS(s,s);
	while(m--){
		cin>>x>>y;
		cout<<lca(x,y)<<endl;	
	}
	return 0;
}
