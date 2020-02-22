#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[1000010],sum[1000010];
long long Maxn;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]*=10000;
		Maxn=max(Maxn,a[i]);
	}
	long long l=0,r=Maxn;
	while(l<=r){
		long long mid=(l+r)>>1,Minn=0;
		bool f=0;
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i]-mid;
			if(i>=m){
				Minn=min(Minn,sum[i-m]);
				if(sum[i]>Minn){
					f=1;
					break;
				}
			}
		}
		if(f)l=mid+1;
		else r=mid-1;
	}
	cout<<l/10<<endl;
	return 0;
}
