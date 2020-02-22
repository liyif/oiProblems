#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int cx[8]={0,0,1,1,1,-1,-1,-1};
int cy[8]={1,-1,1,-1,0,1,0,-1};
int ax,ay,sx,sy;
int n,m;
bool f[1700][1700];
bool v[1700][1700];
bool g[1700][1700];
queue<pair<pair<int,int>,int> > que;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char c;
			cin>>c;
			if(c=='X')f[i][j]=0;
			else f[i][j]=1;
		}
	cin>>sx>>sy>>ax>>ay;
	while(sx+sy!=0||ax+ay!=0){
		bool flag=0;
		memset(g,0,sizeof(g));
		memset(v,0,sizeof(v));
		while(!que.empty())que.pop();
		for(int i=0;i<8;i++){
			int px=sx,py=sy;
			while(px>0&&px<=n&&py>0&&py<=m&&f[px][py]){
				v[px][py]=1;
				px+=cx[i],py+=cy[i];
			}		
		}
		que.push(make_pair(make_pair(ax,ay),0));
		g[ax][ay]=0;
		while(!que.empty()&&!flag){
			int ux=que.front().first.first,uy=que.front().first.second;
			int sc=que.front().second;
			que.pop();
			if(!f[ux][uy])continue;
			if(v[ux][uy]){
				flag=1;
				cout<<sc<<endl;
				break;
			}
			for(int i=0;i<4;i++){
				int px=ux+dx[i],py=uy+dy[i];
				if(!g[px][py]&&f[px][py]){
					g[px][py]=1;
					que.push(make_pair(make_pair(px,py),sc+1));
				}
			}
		}
		if(!flag){
			cout<<"Poor Harry"<<endl;
		}
		cin>>sx>>sy>>ax>>ay;
	}
	return 0;
}
