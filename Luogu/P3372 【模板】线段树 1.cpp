#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using Int=const int&;
int n,m;
ll p;
struct node {
	int l,r;
	ll sum;
	ll add;
	ll mul;
};
node tree[400010];
inline int ls(Int k) {
	return k*2;
}
inline int rs(Int k) {
	return ls(k)+1;
}
void up(Int k) {
	tree[k].sum=tree[ls(k)].sum+tree[rs(k)].sum;
	tree[k].sum%=p;
}
void down(Int k){
	if(tree[k].l==tree[k].r)return;
	tree[ls(k)].sum=(tree[ls(k)].sum*tree[k].mul+(tree[ls(k)].r-tree[ls(k)].l+1)*tree[k].add)%p;
	tree[rs(k)].sum=(tree[rs(k)].sum*tree[k].mul+(tree[rs(k)].r-tree[rs(k)].l+1)*tree[k].add)%p;
	tree[ls(k)].mul=(tree[ls(k)].mul*tree[k].mul)%p;
	tree[rs(k)].mul=(tree[rs(k)].mul*tree[k].mul)%p;
	tree[ls(k)].add=(tree[ls(k)].add*tree[k].mul+tree[k].add)%p;
	tree[rs(k)].add=(tree[rs(k)].add*tree[k].mul+tree[k].add)%p;
	tree[k].add=0; 
	tree[k].mul=1;
}
void build(Int l,Int r,Int k) {
	tree[k].l=l;
	tree[k].r=r;
	tree[k].mul=1;
	if(l<r) {
		int mid=(l+r)/2;
		build(l,mid,ls(k));
		build(mid+1,r,rs(k));
		up(k);
	} else cin>>tree[k].sum;
}
ll get(Int l,Int r,Int k) {
	//cout<<k<<endl;
	if(l<=tree[k].l&&tree[k].r<=r)return tree[k].sum%p;
	down(k); 
	int mid=(tree[k].l+tree[k].r)/2;
	ll ans=0;
	if(l<=mid)ans+=get(l,r,ls(k))%p;
	if(mid<r)ans=(ans+get(l,r,rs(k)))%p;
	return ans;
}
void add(Int l,Int r,Int k,ll sum){
	if(l<=tree[k].l&&tree[k].r<=r){
		tree[k].sum=(tree[k].sum+(tree[k].r-tree[k].l+1)*sum)%p;
		tree[k].add=(tree[k].add+sum)%p;
		return;
	}
	down(k);
	int mid=(tree[k].l+tree[k].r)/2;
	if(l<=mid)add(l,r,ls(k),sum);
	if(mid<r)add(l,r,rs(k),sum);
	up(k);
}
void mul(Int l,Int r,Int k,ll sum){
	if(l<=tree[k].l&&tree[k].r<=r){
		tree[k].sum=(tree[k].sum*sum)%p;
		tree[k].add=(tree[k].add*sum)%p;
		tree[k].mul=(tree[k].mul*sum)%p;
		return;
	}
	down(k);
	int mid=(tree[k].l+tree[k].r)/2;
	if(l<=mid)mul(l,r,ls(k),sum);
	if(mid<r)mul(l,r,rs(k),sum);
	up(k);
}
int main() {
	cin>>n>>p;
	build(1,n,1);
	int x,y,z,k;
	cin>>m;
	while(m--){
		cin>>x>>y>>z;
		switch(x){
			
			case 1:cin>>k;mul(y,z,1,k);break;
			case 2:cin>>k;add(y,z,1,k);break;
			case 3:cout<<get(y,z,1)<<endl;break;
		}
	}
	return 0;
}

