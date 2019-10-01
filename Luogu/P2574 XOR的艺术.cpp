#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
char s[200010];
int n,m;
void rd(){
	int k=1;
	s[k]=getchar();
	while(s[k]!='0'&&s[k]!='1')s[k]=getchar();
	while(s[k]=='0'||s[k]=='1')s[++k]=getchar();
}
struct node{
	int l;int r;int num;
	int lazy;
}t[800010];
inline int ls(const int& k){
	return k<<1;
}
inline int rs(const int& k){
	return ls(k)+1;
}
void build(int l,int r,int k){
	t[k].l=l;
	t[k].r=r;
	if(l==r){
		t[k].num=s[l]-'0';
	}
	else {
		int m=(l+r)/2;
		build(l,m,ls(k));
		build(m+1,r,rs(k));
		t[k].num=t[ls(k)].num+t[rs(k)].num;
	}
}
void down(int k){
	if(t[k].lazy%2==0)t[k].lazy=0;
	else {
		t[ls(k)].lazy++;
		t[ls(k)].num=(t[ls(k)].r-t[ls(k)].l+1)-t[ls(k)].num;
		t[rs(k)].lazy++;
		t[rs(k)].num=(t[rs(k)].r-t[rs(k)].l+1)-t[rs(k)].num;
		t[k].lazy=0;
	}
}
void change(int l,int r,int k){
	//cout<<k<<" "<<t[k].l<<" "<<t[k].r<<endl; 
	if(t[k].l>=l&&t[k].r<=r){
		t[k].num=(t[k].r-t[k].l+1)-t[k].num;
		t[k].lazy++;
		return;
	}
	down(k);
	int m=(t[k].l+t[k].r)/2;
	if(l<=m)change(l,r,ls(k));
	if(r>m)change(l,r,rs(k));
	t[k].num=t[ls(k)].num+t[rs(k)].num;
}
int get(int l,int r,int k){
	if(t[k].l>=l&&t[k].r<=r){
		return t[k].num;
	}
	down(k);
	int m=(t[k].l+t[k].r)/2;
	int ans=0;
	if(l<=m)ans+=get(l,r,ls(k));
	if(r>m)ans+=get(l,r,rs(k));
	return ans;
}
int main(){
	read(n);
	read(m);
	scanf("%s",s+1);
	build(1,n,1);
	int x,y,z;
	while(m--){
		read(x),read(y),read(z);
		if(x==0){
			change(y,z,1);
		}
		else {
			printf("%lld\n",get(y,z,1));
		}
	}
	return 0;
}
