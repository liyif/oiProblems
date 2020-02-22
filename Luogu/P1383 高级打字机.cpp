#include<bits/stdc++.h>
using namespace std;
int n,tot;
const int MAXN=100010;
struct node{
	int ls,rs;
	char ch;
}tree[MAXN<<5];
int build(int l,int r){
	int k=++tot;
	tree[k].ch='/';
	if(l<r){
		int m=(l+r)/2;
		tree[k].ls=build(l,m);
		tree[k].rs=build(m+1,r);
	}
	return k;
}
char query(int k,int l,int r,int p){
	if(l==r)return tree[k].ch;
	int m=(l+r)/2;
	if(p<=m){
		return query(tree[k].ls,l,m,p);
	}
	else return query(tree[k].rs,m+1,r,p);
}
int t[MAXN];
int add(int k,int l,int r,int p,char ch){
	int q=++tot;
	tree[q]=tree[k];
	if(l==r){
		tree[q].ch=ch;
		return q;
	}
	int m=(l+r)/2;
	if(p<=m)
		tree[q].ls=add(tree[k].ls,l,m,p,ch);
	else tree[q].rs=add(tree[k].rs,m+1,r,p,ch);
	return q;
}
void dfs(int k){
	if(tree[k].ch!='/')cout<<tree[k].l<<" "<<tree[k].r<<" "<<tree[k].ch<<endl;
	if(tree[k].ls!=0)dfs(tree[k].ls);
	if(tree[k].rs!=0)dfs(tree[k].rs);
}
int len[MAXN];
int now=0;
int main(){
	cin>>n;
	char opt;
	t[0]=build(1,100010);
	//dfs(t[0]);
	for(int i=1;i<=n;i++){
		cin>>opt;
		char x;
		int y;
		switch(opt){
			case 'T':
				cin>>x;
				now++;
				len[now]=len[now-1]+1;
				t[now]=add(t[now-1],1,100010,len[now],x);
				break;
			case 'U':
				cin>>y;
				now++;
				len[now]=len[now-y-1];
				t[now]=t[now-y-1];
				break;
			case 'Q':
				cin>>y;
				cout<<query(t[now],1,100010,y)<<endl;
				break;
		}
	}
	return 0;
}
