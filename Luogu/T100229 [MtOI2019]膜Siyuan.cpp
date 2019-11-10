#include<bits/stdc++.h>
using namespace std;
int a[10],b[10],c[10];
int n,m;
long long ans;
int sa,sb,sc;
bool check(int x,int y,int z){		
	for(int j=1;j<=n;j++){
		if((abs(a[j]-x) xor abs(b[j]-y) xor abs(c[j]-z))!=9){
			//cout<<j<<" "<<x<<" "<<y<<" "<<z<<endl;
			return false;
		}
	}
	return true;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	int x,y,z;
	for(int i=2;i<=m;i+=2){
		for(int j=2;j<=m;j+=2)
			for(int k=2;k<=m;k+=2)
		if(check(i,j,k))ans++;
	}
	cout<<ans<<endl;
	return 0;
}
