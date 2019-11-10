#include<bits/stdc++.h>
using namespace std;
int val[200010],to[200010],nxt[200010];
int head[20010],tot;
void addEd(int x,int y,int v){
	val[++tot]=v;
	to[tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int n,m;
int lbound,rbound;
char col[20010];
bool f;
bool bfs(const int &mid){
	queue<int>que;
	memset(col,0,sizeof(col));
	for(int i=1;i<=n;i++){
		if(!col[i]){
			que.push(i);
			col[i]=1;
			while(!que.empty()){
				int x=que.front();
				que.pop();
				for(int i=head[x];i;i=nxt[i])
					if(val[i]>=mid){
						if(!col[to[i]]){
							col[to[i]]=3-col[x];
							que.push(to[i]);
						}
						else if(col[to[i]]==col[x])return false;
					}
			}
		}
	}
	return true;
}
int main(){
	int p;
	cin>>n>>m;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		rbound=max(rbound,z);
		p=x;
		addEd(x,y,z);
		addEd(y,x,z);
	}
	rbound++;
	while(lbound+1<rbound){
		int mid=(lbound+rbound)/2;
		if(bfs(mid))rbound=mid;
		else lbound=mid;
	}
	cout<<lbound<<endl;
	return 0;
}
