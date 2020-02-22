#include<bits/stdc++.h>
using namespace std;
int n,m,bl,curl,curr;
int c[50010];
int cnt[50010];
struct node{
	int l,r,id;
}q[50010];
int sum[50010],num[50010];
int ans;
inline bool cmp(const node& x,const node& y){
	return (x.l/bl==y.l/bl)?x.r<y.r:x.l<y.l;
}
void del(int x){
	x=c[x];
	cnt[x]--;
	if(cnt[x]>0)ans+=cnt[x]*(cnt[x]-1)-(cnt[x]+1)*cnt[x];
}
void add(int x){
	x=c[x];
	cnt[x]++;
	if(cnt[x]>1)ans+=cnt[x]*(cnt[x]-1)-(cnt[x]-1)*(cnt[x]-2);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=m;i++){
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	bl=(int)ceil(pow(n,0.5));
	sort(q+1,q+1+m,cmp);
	for(int i=q[1].l;i<=q[1].r;i++)add(i);
	int id=q[1].id;
	curl=q[1].l,curr=q[1].r;
	sum[id]=ans;
	num[id]=(q[1].r-q[1].l+1)*(q[1].r-q[1].l);
	int gcd=__gcd(sum[id],num[id]);
	sum[id]/=gcd;
	num[id]/=gcd;
	for(int i=2;i<=m;i++){
		int l=q[i].l,r=q[i].r;
		while(curl<l)del(curl++);
		while(curr<r)add(++curr);
		while(curl>l)add(--curl);
		while(curr>r)del(curr--);
		sum[q[i].id]=ans;
		num[q[i].id]=(r-l+1)*(r-l);
		int gcd=__gcd(sum[q[i].id],num[q[i].id]);
		sum[q[i].id]/=gcd;
		num[q[i].id]/=gcd;
	}
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<"/"<<num[i]<<endl;
	return 0;
}
