#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int l,r;
};
inline bool operator <(const node& l,const node& r){
	return l.r<r.r;
}
set<node> a;
inline int A(const int &l,const int &r ){
	set<node>::iterator i=a.lower_bound(node{l,l});
	int k=0;
	while(i!=a.end()&&i->l<=r){
		i=a.erase(i);
		++k;
	}
	a.insert(node{l,r});
	return k;
	
}
void read(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
void readc(char &x){
	x=getchar();
	while(x!='A'&&x!='B')x=getchar();
}
int main(){
	read(n);
	char c;
	while(n--){
		readc(c);
		if(c=='A'){
			int x,y;
			read(x);read(y);
			printf("%d\n",A(x,y));
		}
		else printf("%d\n",a.size());
	}
	return 0;
} 
