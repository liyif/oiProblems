#include<bits/stdc++.h>
using namespace std;
int n,m,s;
struct ed{
	int to,next,val;
}edge[200010];
int head[100010],tot;
int dis[100010];
bool vis[100010];
inline void add(int x,int y,int v){
	edge[++tot].to=y;
	edge[tot].val=v;
	edge[tot].next=head[x];
	head[x]=tot;
}
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
}
struct node{
	int i,sum;
};
bool operator>(node l,node r){
	return l.sum>r.sum;
}
priority_queue<node,deque<node>,greater<node> >que;
int main(){
	//memset(dis,127/3,sizeof(dis));
	read(n);read(m);read(s);
	int x,y,z;
	for(int i=1;i<=m;++i){
		read(x),read(y),read(z);
		add(x,y,z);
	}
	que.push(node{s,0});
	while(!que.empty()){
		node x=que.top();
		que.pop();
		//cout<<x.i<<endl;
		if(vis[x.i])continue;
		vis[x.i]=1;
		dis[x.i]=x.sum;
		for(int i=head[x.i];i;i=edge[i].next){
			//cout<<edge[i].to<<" ";
			if(!vis[edge[i].to])
				que.push(node{edge[i].to,x.sum+edge[i].val});
		}
	}
	for(int i=1;i<=n;++i)
		cout<<dis[i]<<" ";
	return 0;
}

