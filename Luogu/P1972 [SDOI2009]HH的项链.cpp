#include<bits/stdc++.h>
using namespace std;
int a[500010],c[500010];
int f[500010];
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
int anss[500010];
struct Q{
	int l,r,p;
}q[500010];
bool cmp(Q a,Q b){
	return a.r<b.r;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>q[i].l>>q[i].r;
		q[i].p=i; 
	}
	sort(q+1,q+1+m,cmp);
	int nx=1;
	for(int i=1;i<=m;i++){
		for(int j=nx;j<=q[i].r;j++){
			if(f[a[j]])
				add(f[a[j]],-1);
			add(j,1);
			f[a[j]]=j;
		}
		nx=q[i].r+1;
		anss[q[i].p]=get(q[i].r)-get(q[i].l-1);
	}
	for(int i=1;i<=m;i++)
		cout<<anss[i]<<endl;
	return 0;
}

