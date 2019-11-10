#include<bits/stdc++.h>
using namespace std;
int ax[510],ay[510];
inline double dist(int l,int r){
	return sqrt(pow(ax[l]-ax[r],2)+pow(ay[l]-ay[r],2));
}
int s,p;
int tot;
bool v[510];
int fd[250020];
int find(int k){
	if(fd[k]==k)return k;
	return fd[k]=find(fd[k]);
}
struct node{
	int x,y;
	double v;
}a[250010];
bool cmp(node x,node y){
	return x.v<y.v;
}
int main(){
	cin>>s>>p;
	for(int i=1;i<=p;i++)
		cin>>ax[i]>>ay[i];
	for(int i=1;i<=p;i++)
		for(int j=1;j<=p;j++){
			a[++tot].x=i;
			a[tot].y=j;
			a[tot].v=dist(i,j);	
		}
	for(int i=1;i<=tot;i++)
		fd[i]=i;
	sort(a+1,a+1+tot,cmp);
	int k=0;
	double ans;
	for(int i=1;i<=tot;i++){
		int fl=find(a[i].x),fr=find(a[i].y);
		if(fl!=fr){
			fd[fl]=fr;
			k++;
			ans=a[i].v;
		}
		if(k==p-s)break;
	}
	printf("%.2f",ans);
	return 0;
}
