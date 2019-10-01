#include<bits/stdc++.h>
using namespace std;
int t,n; 
int a,b;
double x[10010],y[10010]; 
bool f[10010];
int main(){
	cin>>t;
	while(t--){
		a=0,b=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>f[i];
		double r;
		//cout<<"pa"<<endl;
		for(int i=1;i<=n;i++){
			cin>>r;
			if(f[i])x[++a]=r;
			else y[++b]=r ;
		}
		sort(x+1,x+1+a);
		sort(y+1,y+1+b);
		for(int i=1;i<=b;i++)
			cout<<y[i]<<" ";
		cout<<endl;
		for(int i=1;i<=a;i++)
			cout<<x[i]<<" ";
		cout<<endl;
	}
	return 0;
}

