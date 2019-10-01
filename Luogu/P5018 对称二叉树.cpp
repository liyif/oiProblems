#include<bits/stdc++.h>
using namespace std;
int n;
int sum[1000010];
int l[1000010],r[1000010];
int count(int k){
	int ans=0;
	if(l[k]!=-1)ans+=count(l[k]);
	if(r[k]!=-1)ans+=count(r[k]);
	return ans+1;
}
bool flag;
void check(int cl,int cr){
	if(cl==-1&&cr==-1)return;
	if(flag==0)return;
	if(cl==-1||cr==-1||sum[cl]!=sum[cr]){
		flag=0;
		return ;
	}
	check(l[cl],r[cr]);
	check(r[cl],l[cr]);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sum[i];
	}
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		if(l[i]!=-1&&r[i]!=-1&&sum[l[i]]==sum[r[i]]){
			flag=1;
			check(l[i],r[i]);
			if(flag!=0){
				ans=max(ans,count(i));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
