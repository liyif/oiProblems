#include<bits/stdc++.h>
using namespace std;
long long a=1,n;
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		a*=i;
		while(a%10==0)
			a/=10;
		a%=1000000;
	}
	cout<<a%10<<endl;
	return 0;
}
