#include<bits/stdc++.h>
#define ite set<node>::iterator
using namespace std;
void read(int &x){
	char c=getchar();
	x=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
struct node{
	int l;int r;
	mutable int c;
	node(const int &lr,const int &rr,const int &cr):l(lr),r(rr),c(cr){
	}
	
};
inline bool operator<(const node&p, const node& o){
		return p.l<o.l;
	} 
int n,t,o;
set<node>odt;
bool in[31];
set<node>::iterator split(int k){
	if(k>n)return odt.end();
	ite i=--odt.upper_bound(node(k,k,0));
	if(i->l==k)return i;
	int l=i->l,r=i->r,v=i->c;
	odt.erase(i);
	odt.insert(node(l,k-1,v));
	return odt.insert(node(k,r,v)).first;
}
void assign(int l,int r,int c){
	ite ir=split(r+1),il=split(l);
	odt.erase(il,ir);
	odt.insert(node(l,r,c));
}
int count(int l,int r){
	memset(in,0,sizeof(in));
	int ans=0;
	ite ir=split(r+1),il=split(l);
	for(;il!=ir;il++){
		if(in[il->c]==0){
			++ans;
			in[il->c]=1;
		}
	}
	return ans;
}
int main(){
	read(n),read(t),read(o);
	odt.insert(node(1,n,1));
	while(o--){
		char ch;
		int l,r,c;
		cin>>ch;
		read(l),read(r);
		if(l>r)swap(l,r);
		if(ch=='C'){
			read(c);
			assign(l,r,c);
		}
		else {
			cout<<count(l,r)<<endl;
		}
	}
	return 0;
} 
