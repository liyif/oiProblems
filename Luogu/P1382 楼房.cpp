#include<bits/stdc++.h>
#define ite set<node>::iterator
using namespace std;
void read(int &x){
	int i=1;
	char c=getchar();
	x=0;
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-'){
		i=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x*=i;
}
int n;
struct node{
	int l;int r;
	mutable int v;
	node(const int &lr,const int &rr,const int &cr):l(lr),r(rr),v(cr){
	}
};
inline bool operator<(const node&p, const node& o){
		return p.l<o.l;
}
set<node> odt;
ite split(int k){
	//cerr<<"do"<<k<<endl;
	//if(k>n)return odt.end(); 
	ite i=--odt.upper_bound(node(k,k,0));
	if(i->l==k)return i;
	int l=i->l,r=i->r,v=i->v;
	odt.erase(i);
	//cerr<<"ok"<<k<<endl;
	odt.insert(node(l,k,v));
	return odt.insert(node(k,r,v)).first;
} 
void assign(int l,int r,int v){
	ite ir=split(r),il=split(l);
	odt.erase(il,ir);
	odt.insert(node(l,r,v));
}
struct vsx{
	int l,r,v;
};
inline bool cmp(const vsx& l,const vsx& r){
	return l.v<r.v;
}
vsx que[100010];
int tot=0;
int main(){
	read(n);
	odt.insert(node(-1000000010,1000000010,0));
	int x,y,z;
	while(n--){
		read(x);
		read(y);
		read(z);
		que[tot].l=y;
		que[tot].r=z;
		que[tot].v=x;
		tot++;
	}
	sort(que,que+tot,cmp);
	for(int i=0;i<tot;i++){
		//cerr<<"now"<<que[i].l<<que[i].r<<que[i].v<<endl;
		assign(que[i].l,que[i].r,que[i].v);
		//cerr<<i<<" ";
	}
	for(ite i=++odt.begin();i!=odt.end();i++){
		ite j=(--i)++;
		if(i->v==j->v){
			int l=j->l,r=i->r,v=i->v;
			odt.erase(j,(++i)--);
			odt.insert(node(l,r,v));
		}
	}
	//cerr<<endl;
	cout<<(odt.size()-2)*2+2<<endl;
	ite is=--odt.end();
	cout<<odt.begin()->r<<" 0"<<endl;
	for(ite i=++odt.begin();i!=is;i++)
		cout<<i->l<<" "<<i->v<<"\n"<<i->r<<" "<<i->v<<"\n";
	cout<<is->l<<" 0"<<endl;
	return 0;
}
