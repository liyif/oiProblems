#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,v;
}a[10010]; 
int fd[10010];
int find(int k){
	if(fd[k]==k)return k;
	fd[k]=find(fd[k]);
	return fd[k];
}
void uni(int l,int r){
	int fl=find(l);
	int fr=find(r);
	if(fl!=fr){
		fd[fl]=fr;
	}
}
int n,m,sum;
bool cmp(node l,node r){
	return l.v<r.v;
} 
int main(){
	int x;
	cin>>n;
	for(int i=1;i<=n+2;i++)
		fd[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>x;
			if(x!=0){
				a[++m].x=i;
				a[m].y=j;
				a[m].v=x;
			}
		}
	sort(a+1,a+1+m,cmp);
	int k=0;
	for(int i=1;i<=m;i++){
		if(find(a[i].x)!=find(a[i].y)){
			k++;
			uni(a[i].x,a[i].y);
			//cout<<
			sum+=a[i].v;
		}
		if(k==n-1)break;
	}
	cout<<sum<<endl;
	return 0;
} 
