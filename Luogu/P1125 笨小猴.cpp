#include<bits/stdc++.h>
using namespace std;
string s;
int sum[30];
int maxn=-1;
int minn=100000;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++)
	sum[s[i]-'a']++;
	//for(int i=0;i<26;i++){
	//	cout<<i+'a'<<" "<<sum[i]<<endl;
	//}
	for(int i=0;i<26;i++){
		maxn=max(maxn,sum[i]);
		if(sum[i]!=0)
		minn=min(minn,sum[i]);
	}
	int a=maxn-minn;
	if(a<=1){
		cout<<"No Answer"<<endl<<0;
		return 0;
	}
	for(int i=2;i<=a/2;i++){
		if(a%i==0){
			cout<<"No Answer"<<endl<<0;
			return 0;
		}
	}
	cout<<"Lucky Word"<<endl<<a;
	return 0;
} 
