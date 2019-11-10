#include<bits/stdc++.h>
using namespace std;
int n;
int a,b,ans=1;
int main(){
	cin>>n;
	cin>>a;
	if(a==1)ans++;
	for(int i=1;i<n;i++){
		cin>>b;
		if(b!=a){
			ans++;
			a=b;
		}
	}
	cout<<ans<<endl;
	return 0;
}
