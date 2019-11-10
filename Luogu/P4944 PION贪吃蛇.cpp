#include<bits/stdc++.h>
using namespace std;
int n,m,k,r;
char a[210][210];
struct node{
	int x,y;
};
deque<node> que[40010];
bool al[40010];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int cnt;
void dfs(int k,int fx,int fy,int x,int y){
	node u={x,y};
	que[k].push_back(u);
	for(int i=0;i<4;i++){
		int px=x+dx[i],py=y+dy[i];
		if(!(px==fx&&py==fy)&&a[px][py]=='#')
			dfs(k,x,y,px,py);
	}
}
vector<node>v;
vector<char>t[40010];
void die(int k){
	cnt+=que[k].size();
	while(!que[k].empty()){
		a[que[k].front().x][que[k].front().y]='&';
		que[k].pop_front();
	}
	al[k]=1;
}
struct vs{
	int len,id;
};
bool cmp(vs l,vs r){
	if(l.len==r.len)return l.id<r.id;
	return l.len>r.len;
}
vector<vs>va;
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			node x={i,j};
			if(a[i][j]=='@')v.push_back(x);
			if(a[i][j]=='&')cnt++;
		}
	for(int i=0;i<v.size();i++)
		dfs(i+1,-1,-1,v[i].x,v[i].y);
	r=v.size();
	for(int i=1;i<=r;i++)
		for(int j=1;j<=k;j++){
			char c;
			cin>>c;
			t[i].push_back(c);
		}
	for(int i=0;i<k;i++){
		for(int j=1;j<=r;j++){
			if(al[j])continue;
			int ax=que[j].front().x,ay=que[j].front().y;
			int px=ax,py=ay;
			switch(t[j][i]){
				case 'A':ay--;break;
				case 'D':ay++;break;
				case 'S':ax++;break;
				case 'W':ax--;break;
			}
			if(ax<1||ay<1||ax>n||ay>m){
				die(j);
				continue;
			}
			if(a[ax][ay]=='#'||a[ax][ay]=='@'){
				die(j);
				continue;
			}
			if(a[ax][ay]!='&'){
				a[que[j].back().x][que[j].back().y]='.';
				que[j].pop_back();
			}
			else cnt--;
			node o={ax,ay};
			que[j].push_front(o);
			a[px][py]='#';
			a[ax][ay]='@';
			
		}/*
		for(int l=1;l<=n;l++){
			for(int p=1;p<=m;p++)
				cout<<a[l][p];
			cout<<endl;
		}
		cout<<endl*/;
	}
	for(int i=1;i<=r;i++){
		vs x={que[i].size(),i};
		va.push_back(x);
	}
	sort(va.begin(),va.end(),cmp);
	for(int i=0;i<va.size();i++){
		cout<<va[i].len<<" "<<va[i].id<<endl;
	}
	cout<<cnt<<endl;
	return 0;
}
