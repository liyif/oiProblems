#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
long long gcd(long long x,long long y){
	if(x%y==0)return y;
	return gcd(y,x%y);
}
int main(){
	int x,y;
	cin>>a>>b>>c;
	a=a*b/gcd(a,b);
	a=a*c/gcd(a,c);
	cout<<a; 
	return 0;
}
