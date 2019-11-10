#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int r1,c1,r2,c2;
bool a[110][110];
int ans;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int dep,int x,int y){
	//cout<<dep<<" "<<x<<" "<<y<<endl;
	if(dep>=t){
		if(x==r2&&y==c2)
			ans++;
		return;
	}
	if(abs(r2-x)+abs(c2-y)>t-dep)return;
	//a[x][y]=0;
	for(int i=0;i<4;i++){
		int px=x+dx[i],py=y+dy[i];
		if(a[px][py])dfs(dep+1,px,py);
	}
	//a[x][y]=1;
}
int main(){
	cin>>n>>m>>t;
	char x;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>x;
			if(x=='.')a[i][j]=1;
		}
	cin>>r1>>c1>>r2>>c2;
	dfs(0,r1,c1);
	cout<<ans<<endl;
	return 0;
}
