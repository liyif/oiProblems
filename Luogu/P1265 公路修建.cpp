#include<bits/stdc++.h>
using namespace std;
int n;
int ax[5100],ay[5100];
double ans;
double dis[5100];
bool vis[5100];
inline double dist(int x,int y){ 
	return sqrt(pow(ax[x]-ax[y],2)+pow(ay[x]-ay[y],2));
}
int main(){
	cin>>n;
	memset(dis,127,sizeof(dis));
	for(int i=1;i<=n;i++)
		cin>>ax[i]>>ay[i];
	dis[1]=0;
	for(int i=1;i<=n;i++){
		double msum=99999999;
		int pos=1;
		for(int j=1;j<=n;j++)if(!vis[j]&&dis[j]<msum){
			msum=dis[j];
			pos=j;
		}
		ans+=msum;
		vis[pos]=true;
		for(int j=1;j<=n;j++){
			double a=dist(pos,j);
			if(a<dis[j])dis[j]=a;
		}
	}
	printf("%.2f",ans);
	return 0;
}
