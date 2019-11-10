#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long a[1000100];
long long sum[1000100];
long long ans=1e18;
int main(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=0;i<n-k;i++){
		if(sum[n-1]-sum[i+k]+sum[i]<ans)
			ans=sum[n-1]-sum[i+k]+sum[i];
	}
	cout<<ans<<endl;
	return 0;
}
