#include<bits/stdc++.h>
using namespace std;
priority_queue<int> que;
int n;
int a[100010],b[100010];
int ans[100010]; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int x=a[i]+b[j];
			if(que.size()<n)que.push(x);
			else{
				if(que.top()>x){
					que.pop();
					que.push(x);
				}
				else break;
			}
		}
	for(int i=n;i>=1;--i){
		ans[i]=que.top();
		que.pop();
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}

