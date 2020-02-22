#include<bits/stdc++.h>
using namespace std;
struct block{
	int size;
	int data[20000];
	block():size(0){}
};
block bl[320];
int bls;
inline bool cmp(int x,int y){
	return x>y;
}
void insert(int k,int x){
	//cerr<<endl;
	//for(int i=1;i<=bl[k].size;i++)
	//	cerr<<bl[k].data[i]<<" ";
	//cerr<<endl;
	/*
	int l=1,r=bl[k].size;
	while(l<r){
		int mid=(l+r+1)/2;
		//cerr<<mid<<endl;
		if(bl[k].data[l]<x){
			r=mid-1;
		}
		else {
			l=mid;
		}
	}
	//cerr<<l<<endl;
	for(int i=bl[k].size+1;i>l;i--)
		bl[k].data[i]=bl[k].data[i-1];
	bl[k].data[l]=x;
	bl[k].size++;*/
	bl[k].data[++bl[k].size]=x;
	sort(bl[k].data+1,bl[k].data+1+bl[k].size,cmp);
}
void ins(int x){
	for(int i=1;i<=bls;i++){
		if(bl[i].data[bl[i].size]<=x){
			//cerr<<i<<endl;
			insert(i,x);
			return;
		}
	}
}
int get(int x){
	int sum=0;
	for(int i=0;i<=bls;i++){
		if(sum+bl[i].size>=x){
			return bl[i].data[x-sum];
		}
		else sum+=bl[i].size;
	}
	return 0;
}
int m,q;
int a[100010];

int main(){
	cin>>m>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+m,cmp);
	int fl=ceil(sqrt(m));
	int blj=1;
	for(int i=1;i<=m;i++){
		bl[blj].data[++bl[blj].size]=a[i];
		if(bl[blj].size>fl&&a[i]!=a[i+1])blj++;
	}
	bls=blj;
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(x==1)cout<<get(y)<<endl;
		else ins(y);
	}
	return 0;
}
