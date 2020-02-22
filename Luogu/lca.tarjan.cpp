#include<bits/stdc++.h>
using namespace std;
int head[500010],tot;
int to[1000010],nxt[1000010];
int n,m,s;
void addEd(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;	
}
vector<int>q[500010],qid[500010];
int ans[500010];
int col[500010];
int fd[1000010];
int find(int k){
	if(fd[k]==k)return k;
	return fd[k]=find(fd[k]);
}
void tarjan(int k){
	col[k]=1;
	for(int i=head[k];i;i=nxt[i]){
		int u=to[i];
		if(!col[u]){
			tarjan(u);
			fd[u]=k;
		}
	}
	for(int i=0;i<q[k].size();i++){
		int u=q[k][i];
		if(col[u]==2){
			ans[qid[k][i]]=find(u);
		}
	}
	col[k]=2;

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
int main(){
	read(n),read(m),read(s);
	int x,y;
	for(int i=1;i<n;i++){
		read(x),read(y);
		addEd(x,y);
		addEd(y,x);
	}
	for(int i=1;i<=n;i++)
		fd[i]=i;
	for(int i=1;i<=m;i++){
		read(x),read(y);
		q[x].push_back(y),qid[x].push_back(i);
		q[y].push_back(x),qid[y].push_back(i);
	}
	tarjan(s);
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}
