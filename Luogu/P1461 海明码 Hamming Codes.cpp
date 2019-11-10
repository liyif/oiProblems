#include<bits/stdc++.h>
using namespace std;
int n,b,d;
int sum;
int ans[100];
void dfs(int dep,int x){
	if(dep%10==0)cout<<x<<endl;
	else cout<<x<<" ";
	if(dep>=n)exit(0);
	ans[dep]=x;
	bool f=1;
	for(int i=x;i<=sum;i++){
		f=1;
		for(int j=1;j<=dep;j++)
			if(__builtin_popcount(ans[j]^i)<d)
				f=0;
		if(f)dfs(dep+1,i);
	}
}
int main(){
	cin>>n>>b>>d;
	sum=(1<<b);
	dfs(1,0);
	return 0;
}
