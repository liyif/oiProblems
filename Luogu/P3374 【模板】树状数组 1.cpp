#include<bits/stdc++.h>
using namespace std;
int a[500010],c[500010];
int n,m;
inline int lowbit(const int&i){
	return i&(-i);
}
void add(int i,int x){
	while(i<=n){
		c[i]+=x;
		i+=lowbit(i);
	}
}
int get(int i){
	int ans=0;
	while(i>0){
		ans+=c[i];
		i-=lowbit(i);
	}
	return ans;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		add(i,a[i]);
	}
	int x,y,z;
	while(m--){
		cin>>x>>y>>z;
		switch(x){
			case 1:add(y,z);break;
			case 2:cout<<get(z)-get(y-1)<<endl;break;
		}
	}
	return 0;
}

