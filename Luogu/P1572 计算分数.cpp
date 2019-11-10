#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
struct Number;
struct Expression{
	vector<Number> a;
	friend ostream& operator<<(ostream &,const Expression &);
}; 
struct Number{
	int a,b,c;
	Number():a(0),b(1),c(1){}
	void keep(){
		int x=gcd(a,b);
		a/=x;
		b/=x;
		if(b<0){
			b=-b;
			a=-a;
		}
	}
	friend struct Expression;
	friend Number sqrt(Number);
	friend Number merge(Number,const Number&);
	friend Expression operator+(Number,const Number&);
	friend ostream& operator<<(ostream &,const Number&);	
};

ostream& operator<<(ostream &os,const Number& x){
	if(x.a==0){
		os<<0;
		return os;
	}
	os<<x.a;
	if(x.c!=1){
		os<<"["<<x.c<<"]";
	}
	if(x.b!=1){
		os<<"/"<<x.b;
	}
	return os;
}
Number sqrt(Number x){
	if(x.c!=1||x.a<=0)return x;
	int l=1,r=1,sum=x.a*x.b;
	for(int i=2;i<=sum;i++){
		while(sum%i==0){
			sum/=i;
			if(r%i==0){
				r/=i;
				l*=i;
			}
			else {
				r*=i;
			}
		}
	}
	x.a=l;x.c=r;
	x.keep();
	return x;
}
Number merge(Number a,const Number &b){
	if(a.c!=b.c)return a;
	int x=a.b*b.b/gcd(a.b,b.b);
	a.a*=x/a.b;
	a.a+=b.a*x/b.b;
	a.b=x;
	a.keep();
	return a;
}
Expression operator+(Number a,const Number& b){
	Expression x;
	if(a.c==b.c){
		x.a.push_back(merge(a,b));
		return x;
	}
	x.a.push_back(a),x.a.push_back(b);
	return x;
}

ostream& operator<<(ostream & os,const Expression &x){
	for(int i=0;i<x.a.size();i++){
		if(x.a[i].a>=0&&i!=0)os<<'+';
		os<<x.a[i];
	}
	return os;
}
int main(){
	Number a,b;
	char c,d;
	cin>>a.a>>c>>a.b;
	a.keep();
	while(cin>>c){
		cin>>b.a>>d>>b.b;
		if(c=='-')b.a=-b.a;
		b.keep();
		a=merge(a,b);
	}
	a.keep();
	cout<<a<<endl;
	return 0;
}
