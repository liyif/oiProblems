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
void adds(int l,int r,int x){
	add(l,x);
	add(r+1,-x);
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
		add(i,a[i]-a[i-1]);
	} 
	int x,y,z,k;
	while(m--){
		cin>>x>>y;
		switch(x){
			case 1:cin>>z>>k;adds(y,z,k);break;
			case 2:cout<<get(y)<<endl;break;
		}
	}
	return 0;
}

