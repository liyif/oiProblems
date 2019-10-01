#include<bits/stdc++.h>
using namespace std;
int n,m,p1,p2;
long long l,r;
long long sum[100010];
long long s1,s2;
long long ans=9999999999999;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>sum[i];
	cin>>m>>p1>>s1>>s2;
	sum[p1]+=s1;
	for(int i=1;i<m;i++){
		l+=sum[i]*(m-i);
	}
	for(int i=m+1;i<=n;i++){
		r+=sum[i]*(i-m);
	}
	//cout<<l<<" "<<r<<endl;
	for(int i=1;i<=n;i++){
		long long a=abs(l+s2*(m-i)-r);
		//cout<<i<<" "<<a<<endl;
		if(a<ans){
			p2=i;
			ans=a;
		}
	}
	cout<<p2<<endl;
	return 0;
}
