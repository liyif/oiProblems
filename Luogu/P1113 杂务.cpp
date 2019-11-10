#include<bits/stdc++.h>
using namespace std;
int ans;
int tim[10010];
int n;
int main(){
	int a,b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>tim[i];
		b=tim[i];
		int x;
		do{
			cin>>x;
			tim[i]=max(tim[i],b+tim[x]);
		}while(x!=0);
		ans=max(ans,tim[i]);
	}
	cout<<ans<<endl;
	return 0;
}
