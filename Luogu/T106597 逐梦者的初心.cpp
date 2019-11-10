#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[1000100];
deque<int>que;
bool check(int l){
	for(int i=0;i<=l;i++){
		if(que[que.size()-l+i-1]==s[i])return false;
	}
	return true;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];
	int ans=0;
	while(m--){
		int opt,ch;
		cin>>opt>>ch;
		if(opt==0){
			que.push_back(ch);
			ans=0;
			for(int i=0;i<que.size();i++)
				if(check(i))ans++;
		}
		else {
			que.push_front(ch);
			if(check(que.size()-1))ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
