#include<bits/stdc++.h>
using namespace std;
int n,l;
int h[100010],w[100010];
int f[100010];

int main(){
	cin>>n>>l;
	for(int i=1;i<=n;i++)
		cin>>h[i]>>w[i];
	memset(f,127,sizeof(f));
	f[0]=0;
	int sum=0,last=1;

	for(int i=1;i<=n;i++){
		sum+=w[i];
		while(sum>l)sum-=w[last++];
		int high=0;
		for(int j=last;j<=i;j++){
			high=max(high,h[j]);
		}
		f[i]=min(f[i],f[last-1]+high);
	}
	for(int i=1;i<=n;i++)
		cout<<f[i]<<" ";
	return 0;
}
