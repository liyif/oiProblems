#include<bits/stdc++.h>
using namespace std;
int to[800010],nxt[800010];
int head[800010],tot;
int n,m,k;
void addEd(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
vector<int> vec;
bool flag[800010];
int fd[800010];
int cnt=1;
void Union(int,int);
void dfs(int u,int s){
	Union(u,s);
	for(int i=head[u];i;i=nxt[i]){
		if(!flag[to[i]]&&fd[to[i]]==to[i]){
			dfs(to[i],s);
		}
	}
}
int find(int k){
	if(fd[k]==k)return k;
	return fd[k]=find(fd[k]);
}
void Union(int l,int r){
	int fl=find(l),fr=find(r);
	if(fl!=fr){
		fd[fl]=fr;
	}
}
int ans[800010];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		fd[i]=i;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		addEd(x,y);
		addEd(y,x);
	}
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>x;
		vec.push_back(x);
		flag[x]=1;
	}
	for(int i=0;i<n;i++){
		if(!flag[i]&&fd[i]==i){
			dfs(i,i);
			ans[k]++;
		}	
	}
	for(int i=vec.size()-1;i>=0;i--){
		ans[i]=ans[i+1]+1;
		int u=vec[i];
		flag[u]=0;
		for(int j=head[u];j;j=nxt[j]){
			if(flag[to[j]])continue;
			int fl=find(u),fr=find(to[j]);
			if(fl!=fr){
				ans[i]--;
				fd[fl]=fr;
			}	
		}

	}
	for(int i=0;i<=k;i++)
		cout<<ans[i]<<endl;
	return 0;
}
