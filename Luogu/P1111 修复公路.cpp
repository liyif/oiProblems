#include<bits/stdc++.h>
using namespace std;
int fd[1010];
int find(int k){
	if(fd[k]==k)return k;
	return fd[k]=find(fd[k]);
}
struct node{
	int x,y,t;
}ed[200010];
bool cmp(node l,node r){
	return l.t<r.t;
}
int n,m;
int num;
int main(){
	cin>>n>>m;
	num=n;
	for(int i=1;i<=n;i++)
		fd[i]=i;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>ed[i].x>>ed[i].y>>ed[i].t;
	}
	sort(ed+1,ed+1+m,cmp);
	for(int i=1;i<=m;i++){
		int fl=find(ed[i].x),fr=find(ed[i].y);
		if(fl!=fr){
			fd[fl]=fr;
			num--;
		}
		if(num<=1){
			cout<<ed[i].t<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
