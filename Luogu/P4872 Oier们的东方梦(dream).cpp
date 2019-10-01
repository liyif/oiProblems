#include<bits/stdc++.h>
#define INF 707406378
using namespace std;
struct node{
	short x,y;
	int sum;
	char cn;
};
bool operator>(const node&l,const node&r){
	return l.sum>r.sum;
}
void readchar(char &c){
	c=getchar(); 
	while(c==' '||c=='\n'||c=='\r')c=getchar();
} 
vector<pair<short,short> >vx;
int m,n;
int dis[1010][1010][3];
char s[1010][1010][3];
int xijian[3]; 
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int ex,ey,sx,sy;
bool vis[1010][1010][3];
priority_queue<node,deque<node>,greater<node> >que;
int main(){
	memset(xijian,127/3,sizeof(xijian));
	memset(dis,127/3,sizeof(dis));
	memset(s,'U',sizeof(s));
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			readchar(s[i][j][0]);
			if(s[i][j][0]=='S')sx=i,sy=j;
			if(s[i][j][0]=='E')ex=i,ey=j;
			if(s[i][j][0]=='X')vx.push_back(make_pair(i,j));
			if(s[i][j][0]=='M')s[i][j][0]=0;
			switch(s[i][j][0]){
				case '2':case '3':case '4':s[i][j][1]=0;break;
				default:s[i][j][1]=s[i][j][0];break;
			}
			switch(s[i][j][1]){
				case '1':case '5':s[i][j][2]=0;break;
				default:s[i][j][2]=s[i][j][1];break;
			}
		}
	
	que.push(node{sx,sy,0,0});
	while(!que.empty()){
		node x=que.top();
		que.pop();
		if(x.x==ex&&x.y==ey){
			cout<<x.sum<<endl;
			return 0;
		}
		if(vis[x.x][x.y][x.cn])continue;
		vis[x.x][x.y][x.cn]=1;
		dis[x.x][x.y][x.cn]=x.sum;
		if(s[x.x][x.y][x.cn]=='X'&&xijian[x.cn]>x.sum){
			xijian[x.cn]=x.sum;
			for(int i=0;i<vx.size();++i){
				if(!vis[vx[i].first][vx[i].second][x.cn])
					que.push(node{vx[i].first,vx[i].second,x.sum+1,x.cn});
			}
			//cerr<<endl;
		}
		if(s[x.x][x.y][x.cn]=='4'){
			que.push(node{x.x,x.y,x.sum,1});
		}
		if(s[x.x][x.y][x.cn]=='5'){
			que.push(node{x.x,x.y,x.sum+5,2});
		}
		for(int i=0;i<4;++i){
			short cx=x.x+dx[i],cy=x.y+dy[i];
			if(vis[cx][cy][x.cn]||s[cx][cy][x.cn]=='U')continue;
			switch(s[cx][cy][x.cn]){
				case '1':break;
				case '2':que.push(node{cx,cy,x.sum+4,x.cn});break;
				case '3':que.push(node{cx,cy,x.sum+9,x.cn});break;
				default:que.push(node{cx,cy,x.sum+1,x.cn});break;
			}
		}
		
	}
	cout<<"We want to live in the TouHou World forever";
	return 0;
}

