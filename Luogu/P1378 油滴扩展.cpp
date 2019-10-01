#include<bits/stdc++.h>
#define pi 3.14159265359
using namespace std;
int n;
double px,py,qx,qy;
double mx[10],my[10];
double ans=30000000;
inline double disa(const double& x1,const double& y1,const double& x2,const double& y2) {
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
double pan[10];
double dis[10][10];
double getp(int id) {
	double ans;
	ans=min(min(abs(qx-mx[id]),min(abs(mx[id]-px),abs(my[id]-py))),abs(qy-my[id]));
	for(int i=0;i<=n;i++){
		if(pan[i]!=-1)
		ans=min(ans,dis[id][i]-pan[i]);
	}
	return ans;
}
inline double ar(const double &pa){
	return pa*pa*pi; 
}
void dfs(int dep,double area) {
	
	if(dep==n) {
		cout<<"reach"<<area<<endl;
		if(area<ans)ans=area;
		return;
	}
	for(int i=1; i<=n; i++) {
		if(pan[i]==-1) {
			
			pan[i]=getp(i);
			cout<<dep<<" "<<area<<" "<<i<<" "<<pan[i]<<" "<<ar(pan[i])<<endl;
			dfs(dep+1,area+ar(pan[i]));
			pan[i]=-1;
		}
	}
}
int main() {
	
	double x1,x2,y1,y2;
	cin>>n>>x1>>y1>>x2>>y2;
	px=min(x1,x2);
	py=min(y1,y2);
	qx=max(x1,x2);
	qy=max(y2,y2);
	double width=abs(qx-px),height=abs(qy-py);
	
	for(int i=1; i<=n; i++) {
		cin>>mx[i]>>my[i];
	}
	for(int i=1; i<=n; i++) {
		dis[i][0]=min(min(abs(qx-mx[i]),min(abs(mx[i]-px),abs(my[i]-py))),abs(qy-my[i]));
		for(int j=1; j<=n; j++) {
			if(i==j)dis[i][j]=52000;
			else {
				if(dis[j][i]!=0)dis[i][j]=dis[j][i];
				else dis[i][j]=disa(mx[i],my[i],mx[j],my[j]);
			}

		}
	}
	for(int i=1;i<=n;i++)
	pan[i]=-1;
	pan[0]=0;
	cout<<width<<" "<<height<<endl;
	dfs(0,0);
	cout<<int(width*height-ans+0.5);
	return 0;
}
