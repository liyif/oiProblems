#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[200010]; 
priority_queue<int> que1;
priority_queue<int,deque<int>,greater<int> > que2;
int main(){
	int k=1;
	int a;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>x[i];
	}
	int r=1;
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=r;j<=a;j++){
			que1.push(x[j]);
			if(que1.size()==i){
				que2.push(que1.top());
				que1.pop();
			}
		}
		r=a+1;
		cout<<que2.top()<<endl;
		que1.push(que2.top());
		que2.pop();
	}
	return 0;
}

