#include<bits/stdc++.h>
using namespace std;
int t,n,h,r;
double x[1010];
double y[1010];
double z[1010];
bool f;
bool d[1010];
inline double dis(const int &l,const int &r){
	return sqrt(pow(x[l]-x[r],2)+pow(y[l]-y[r],2)+pow(z[l]-z[r],2));
}
void dfs(int k){
	if(f)return;
	if(z[k]+r>=h){
		f=1;
		return;
	}
	if(d[k])return;
	d[k]=1;
	for(int i=1;i<=n;i++){
		if(!d[i]&&dis(k,i)<=2*r)
			dfs(i);
	}
}
int main(){
	cin>>t;
	while(t--){
		memset(d,0,sizeof(d));
		f=0;
		cin>>n>>h>>r;
		for(int i=1;i<=n;i++)
			cin>>x[i]>>y[i]>>z[i];
		for(int i=1;i<=n&&!f;i++){
			if(z[i]<=r)
				dfs(i);
		}
		if(f)
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 
