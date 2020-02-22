#include<bits/stdc++.h>
using namespace std;
int tot;
int to[1010],nex[1010];
int se[1010][7];
int head[1010];
void addEd(int x,int y){
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
int n;
int dfs(int k,int d,int fa){
	for(int i=head[k];i;i=nex[i]){
		
	}
	if(d>4)
}
int main(){
	memset(se,127,sizeof(se));
	cin>>n;
	int x,y;
	for(int i=1;i<n;i++){
		cin>>y;
		addEd(i,y);
		addEd(y,i);
	}

	return 0;
}
