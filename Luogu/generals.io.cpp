#include<bits/stdc++.h>
using namespace std;
int n,m,b;
int ax,ay,bx,by;
int a[10010][10010];
struct node{
	int x,y,v,c;
};
inline bool dist(int lx,int ly,int rx,int ry){
	return abs(lx-rx)+abs(ry-ry);
}
inline bool operator>(node x,node y){
	int disx=dist(x.x,x.y,bx,by);
	int disy=dist(y.x,y.y,bx,by);
	return x.v+disx==y.v+disy?x.c>y.c:x.v+disx>y.v+disy;
}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
priority_queue<node,deque<node>,greater<node> >que;
void bfs(){
	node x={ax,ay,0,0};
	que.push(x);
	while(!que.empty()){
		node p=que.top();
		que.pop();
		if(p.x==bx&&p.y==by){
			cout<<p.v<<endl<<p.c;
			return;
		}
		for(int i=0;i<4;i++){
			int px=p.x+dx[i],py=p.y+dy[i];
			if(p.c+a[px][py]>=b)continue;
			node q={px,py,p.v+1,p.c+a[px][py]};
			que.push(q);
		}
	}
}
int main(){
	memset(a,127,sizeof(a));
	cin>>n>>m>>b;
	cin>>ax>>ay>>bx>>by;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	bfs();
	return 0;
}
