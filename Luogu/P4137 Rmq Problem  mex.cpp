#include<bits/stdc++.h>
using namespace std;
int n,m,bl,curl,curr;
int a[200010],cnt[200010],ans;
int num[200010];
struct node{
	int id,l,r;
}q[200010];
bool cmp(node x,node y){
	return (x.l/bl==y.l/bl)?x.r<y.r:x.l<y.l;
}
void del(int k){
	if(a[k]>n)return;
	if(!(--cnt[a[k]])){
		if(a[k]<ans)ans=a[k];
	}
}
void add(int k){
	if(a[k]>n)return;
	++cnt[a[k]];
	while(cnt[ans]!=0)
		ans++;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[0]=n+1;
	for(int i=1;i<=m;i++){
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	//ans=n;
	bl=(int)ceil(pow(n,0.5));
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=m;i++){
		int l=q[i].l,r=q[i].r;
		while(curl>l)add(--curl);
		while(curr<r)add(++curr);
		while(curl<l)del(curl++);
		while(curr>r)del(curr--);
		num[q[i].id]=ans;
	}
	for(int i=1;i<=m;i++)
		cout<<num[i]<<endl;
	return 0;
}
