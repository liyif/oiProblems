#include<bits/stdc++.h>
using namespace std;
int t[100010];
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	sort(t+1,t+n+1);
	for(int i=1;i<=n;i++){
		ans+=t[i]*i;
	}
	cout<<ans<<endl;
	return 0;
}
