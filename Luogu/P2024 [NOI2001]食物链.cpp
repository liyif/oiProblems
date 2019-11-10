#include<bits/stdc++.h>
using namespace std;
int fd[3*50010];
int find(int k){
	if(fd[k]==k)return k;
	return fd[k]=find(fd[k]);
}
int n,m;
int ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=3*n;i++)
		fd[i]=i;
	int a,b,c;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		if(b>n||c>n)ans++;
		else {
			if(a==1){
				if(find(n+b)==find(c)||find(b)==find(n+c))ans++;
				else {
					fd[find(b)]=find(c);
					fd[find(n+b)]=find(n+c);
					fd[find(n+n+b)]=find(n+n+c);
				}
			}
			else {
				if(find(b)==find(c)||find(b)==find(n+c))ans++;
				else {
					fd[find(n+b)]=find(c);
					fd[find(b)]=find(n+n+c);
					fd[find(n+n+b)]=find(n+c);
				}
			}
		}	
	}
	cout<<ans<<endl;
	return 0;
}
