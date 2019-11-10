#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,next;
}edge[100010];
int head[5010],tot;
void addEd(int x,int y){
	edge[++tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}
int n,m;
int dfn[5010],low[5010],sum[5010];
bool fin[5010];
stack<int> sta;
int t;
int cnt,ans=-1;
int cpi[5010];
void tarjan(int k){
	++t;
	dfn[k]=low[k]=t;
	fin[k]=1;
	sta.push(k);
	for(int i=head[k];i;i=edge[i].next){
		if(!dfn[edge[i].to]){
			tarjan(edge[i].to);
			low[k]=min(low[k],low[edge[i].to]);
		}
		else if(fin[edge[i].to])
			low[k]=min(low[k],dfn[edge[i].to]);
	}
	if(low[k]==dfn[k]){
		++cnt;
		while(sta.top()!=k){
			fin[sta.top()]=0;
			cpi[sta.top()]=cnt;
			sum[cnt]++;
			sta.pop();
		}
		fin[sta.top()]=0;
		cpi[sta.top()]=cnt;
		sum[cnt]++;
		sta.pop();
	}
}
int main(){
	cin>>n>>m;
	int a,b,t;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>t;
		addEd(a,b);
		if(t==2)addEd(b,a);
	}
	int cps;
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++){
		if(sum[i]>ans){
			ans=sum[i];
			cps=i;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		if(cpi[i]==cps){
			cout<<i<<" ";
		}
	} 
	return 0;
}
