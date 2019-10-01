#include<bits/stdc++.h>
using namespace std;
struct node{
	vector<int> to;
};
node ed[5010];
int n,m;
void dfs(int k,int fa){
	cout<<k<<" ";
	for(int i=0;i<ed[k].to.size();i++)
		if(ed[k].to[i]!=fa){
			dfs(ed[k].to[i],k);
		}
		
}
vector<pair<int,int> >vec;
int *s,*p;
int j;
int tot;
bool f[5010];
bool z,u;
void dfsr(int k,int fa){
	if(z)return;
	if(k==vec[j].first&&fa==vec[j].second)return;
	if(k==vec[j].second&&fa==vec[j].first)return;
	if(f[k]){
		z=1;
		return;
	}
	f[k]=1;
	if(u&&k>s[tot]){
		z=1;
		return;
	}
	if(k<s[tot])u=0;
	p[tot++]=k;
	
	//system("pause");
	for(int i=0;i<ed[k].to.size();i++)
		if(ed[k].to[i]!=fa){
			dfsr(ed[k].to[i],k);
		}
		
}
bool cmp(){
	if(tot!=n)return false;
	for(int i=0;i<tot;i++){
		if(s[i]>p[i])return true;
		if(s[i]<p[i])return false;
	}
	return false;
}
int main(){
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		ed[x].to.push_back(y);
		ed[y].to.push_back(x);
		vec.push_back(make_pair(y,x));
	}
	for(int i=1;i<=n;i++){
		sort(ed[i].to.begin(),ed[i].to.end());
	}
	if(m==n-1)
		dfs(1,0);
	else{
		s=new int[n+5];
		for(int i=0;i<n;i++){
			s[i]=n-i;
		}
		for(j=0;j<vec.size();j++){
			tot=0;
			z=0;
			u=1;
			p=new int[n+5];
			memset(f,0,sizeof(f));
			dfsr(1,0);
			if(cmp()){
				delete[] s;
				s=p;
			}
		}
		for(int i=0;i<n;i++){
			cout<<s[i]<<" ";
		}	
	}
	return 0;
}
