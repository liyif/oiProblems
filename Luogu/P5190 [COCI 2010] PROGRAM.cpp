#include<bits/stdc++.h>
using namespace std;
int n,k;
long long x[1000010],seq[1000010],cnt[1000010];
int main(){
	cin>>n>>k;
	int a;
	for(int i=1;i<=k;i++){
		cin>>a;
		cnt[a]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j+=i)
			seq[j]+=cnt[i];
	}
	for(int i=1;i<=n;i++)
		x[i]=x[i-1]+seq[i-1];
	int q,b;
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		cout<<x[b+1]-x[a]<<endl;
	}
	return 0;
}
