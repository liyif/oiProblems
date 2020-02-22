#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
struct node{
	int l,r,v;	
}tree[MAXN<<5];
int a[MAXN];
int tot;
inline int clone(int k){
	tree[++tot]=tree[k];
	return tot;
}
int build(int l,int r){
	int k=++tot;
	if(l==r){
		tree[k].v=a[l];
		return k;
	}
	int mid=(l+r)/2;
	tree[k].l=build(l,mid);
	tree[k].r=build(mid+1,r);
	return k;
}
int add(int p,int l,int r,int v,int t){
	int k=clone(p);
	if(l==r){
		tree[k].v=v;
		return k;
	}
	int mid=(l+r)/2;
	if(t<=mid)tree[k].l=add(tree[p].l,l,mid,v,t);
	else tree[k].r=add(tree[p].r,mid+1,r,v,t);
	return k;
}
int query(int k,int l,int r,int t){
	if(l==r)
		return tree[k].v;
	int mid=(l+r)/2;
	if(t<=mid)return query(tree[k].l,l,mid,t);
	else return query(tree[k].r,mid+1,r,t);
}
int n,m;
int rt[MAXN];
void dfs(int k,int l,int r){
	if(l==r)cout<<tree[k].v<<" ";
	else {
		int mid=(l+r)/2;
		dfs(tree[k].l,l,mid);
		dfs(tree[k].r,mid+1,r);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	rt[0]=build(1,n);
	int a,b,c,d;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		if(b==1){
			cin>>d;
			rt[i]=add(rt[a],1,n,d,c);
		}
		else {
			cout<<query(rt[a],1,n,c)<<endl;
			rt[i]=rt[a];
		}
	}
	return 0;
}
