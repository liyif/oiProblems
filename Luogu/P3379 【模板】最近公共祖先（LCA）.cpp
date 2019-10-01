#include<bits/stdc++.h>
using namespace std;
struct node {
	int to,next;
};
int head[500010],tot;
int dep[500010];
int fs[500010][23];
int lg[500010];
int n,m,s;
node edge[1000010];
void add(int x,int y) {
	edge[++tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}
void dfs(int x,int f) {
	dep[x]=dep[f]+1;
	fs[x][0]=f;
	for(int i=1; (1<<i)<=dep[x]; i++) {
		fs[x][i]=fs[fs[x][i-1]][i-1];
	}
	for(int i=head[x]; i!=-1; i=edge[i].next) {
		if(edge[i].to!=f)
			dfs(edge[i].to,x);
	}
}
int lca(int x,int y) {
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])
		x=fs[x][lg[dep[x]-dep[y]]-1];
	if(x==y)return x;
	for(int i=lg[dep[x]]-1; i>=0; i--) {
		if(fs[x][i]==fs[y][i])continue;
		x=fs[x][i],y=fs[y][i];
	}
	return fs[x][0];
}
void read(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int main() {
	memset(head,-1,sizeof(head));
	read(n),read(m),read(s);
	int x,y;
	for(int i=1; i<n; i++) {
		read(x);read(y);
		add(x,y);
		add(y,x);
	}
	dfs(s,0);
	for(int i=1; i<=n; i++) {
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	}
	for(int i=1; i<=m; i++) {
		read(x);
		read(y);
		cout<<lca(x,y)<<endl;
	}
	return 0;
}

