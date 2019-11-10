#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int head[100010],tot;
int to[200010],nxt[200010],val[200010];
void addEd(int x,int y,int v){
	to[++tot]=y;
	val[tot]=v;
	nxt[tot]=head[x];
	head[x]=tot;
}
struct node{
	int x,y,v;
}as[1000010];
int cnt;
int fd[1000010];
int find(int k){
	if(fd[k]==k)return k;
	return fd[k]=find(fd[k]);
}
bool cmp(node x,node y){
	return x.v>y.v;
}
vector<int>qx[100010],qid[100010];
vector<int>px[100010],py[100010],pid[100010];
int col[100010];
int sum[100010];
int finds(int k){
	//cout<<k<<" "<<sum[k]<<" "<<fd[k]<<endl;
	if(fd[k]==k)return k;
	int f=finds(fd[k]);
	
	sum[k]=min(sum[k],sum[fd[k]]);
	return fd[k]=f;
}
int getus(int k){
	if(fd[k]==k)return sum[k];
	//cout<<k<<" "<<sum[k]<<" "<<fd[k]<<endl;
	//sum[k]=min(sum[k],sum[fd[k]]);
	return sum[k]=min(sum[k],getus(fd[k]));
}
int ans[400010];
void tarjan(int k){
	col[k]=1;
	for(int i=head[k];i;i=nxt[i]){
		int u=to[i];
		if(col[u])continue;
		tarjan(u);
		sum[u]=val[i];
		fd[u]=k;
	}
	for(int i=0;i<qx[k].size();i++){
		if(col[qx[k][i]]==2){
			//for(int j=1;j<=n;j++)cout<<fd[j]<<"/"<<sum[j]<<" ";
			//cout<<endl;
			int lca=finds(qx[k][i]);
			//cout<<k<<endl;
			//cout<<lca<<endl;
			//cout<<getus(qx[k][i])<<endl;
			//cout<<getus(2)<<endl;
			px[lca].push_back(k);
			py[lca].push_back(qx[k][i]);
			pid[lca].push_back(qid[k][i]);
		}
	}
	for(int i=0;i<px[k].size();i++){
		ans[pid[k][i]]=min(getus(px[k][i]),getus(py[k][i]));
	}
	col[k]=2;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		fd[i]=i;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		as[i].x=x,as[i].y=y,as[i].v=z;
		
	}
	sort(as+1,as+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fl=find(as[i].x),fr=find(as[i].y);
		if(fl!=fr){
			fd[fl]=fr;
			addEd(as[i].x,as[i].y,as[i].v);
			addEd(as[i].y,as[i].x,as[i].v);
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		qx[x].push_back(y);qid[x].push_back(i);
		qx[y].push_back(x);qid[y].push_back(i);
	}
	for(int i=1;i<=n;i++)
		fd[i]=i;
	memset(sum,127,sizeof(sum));
	for(int i=1;i<=n;i++)
		if(!col[i])tarjan(i);
	for(int i=1;i<=q;i++)
		if(ans[i]==0)cout<<-1<<endl;
		else cout<<ans[i]<<endl;
	return 0;
}
