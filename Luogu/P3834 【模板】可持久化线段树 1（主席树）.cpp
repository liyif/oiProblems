#include<bits/stdc++.h>
#define INT const int&
using namespace std;
const int maxn=200010;
int n,m,q,tot;
int a[maxn],b[maxn],t[maxn];
struct node{
	int l,r,sum;
}tree[maxn<<5];
int build(int l,int r){
	int x=++tot;
	tree[x].sum=0;
	if(l<r){
		int mid=(l+r)/2;
		tree[x].l=build(l,mid);
		tree[x].r=build(mid+1,r);
	}
	return x;
}
int update(int k,int l,int r,int v){
	int x=++tot;
	tree[x]=tree[k];
	tree[x].sum++;
	if(l<r){
		int mid=(l+r)/2;
		if(v<=mid)tree[x].l=update(tree[k].l,l,mid,v);
		else tree[x].r=update(tree[k].r,mid+1,r,v);
	}
	return x;
}
int query(int u,int v,int l,int r,int k){
	//cerr<<u<<" "<<v<<" "<<l<<" "
	//<<r<<" "<<k<<endl; 
	if(l>=r)return l;
	int x=tree[tree[v].l].sum-tree[tree[u].l].sum;
	//cerr<<x<<endl;
	int mid=(l+r)/2;
	if(x>=k)return query(tree[u].l,tree[v].l,l,mid,k);
	return query(tree[u].r,tree[v].r,mid+1,r,k-x);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	q=unique(b+1,b+1+n)-b-1;
	t[0]=build(1,q);
	int x,y,z;
	for(int i=1;i<=n;i++){
		int p=lower_bound(b+1,b+1+q,a[i])-b;
		t[i]=update(t[i-1],1,q,p);
	} 
	while(m--){
		cin>>x>>y>>z;
		int r=query(t[x-1],t[y],1,q,z);
		cout<<b[r]<<endl;
	}
	return 0;
}

