#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010],b[10010],c[10010],s[10000001];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=100;j++){
			s[j+(i-1)*100]=a[i]*j*j+b[i]*j+c[i];
		}
	sort(s+1,s+1+n*100);
	for(int i=1;i<=m;i++)
	cout<<s[i]<<" ";
	return 0;
}

