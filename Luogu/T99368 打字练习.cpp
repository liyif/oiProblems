#include<bits/stdc++.h>
using namespace std;
int t;
vector<string> s,x,r,q;
int main(){
	string c;
	getline(cin,c);
	while(c!="EOF"){
		q.push_back(c);
		getline(cin,c);
	}
	getline(cin,c);
	while(c!="EOF"){
		x.push_back(c);
		getline(cin,c);
	}
	cin>>t;
	int ans=0;
	for(int i=0;i<x.size();i++){
		string a;
		
		for(int j=0;j<x[i].size();j++){
			if(x[i][j]=='<')if(a.size()!=0)a.pop_back();
			if(x[i][j]!='<')a.push_back(x[i][j]);
		}
		r.push_back(a);
	}
	for(int i=0;i<q.size();i++){
		string a;
		
		for(int j=0;j<q[i].size();j++){
			if(q[i][j]=='<')if(a.size()!=0)a.pop_back();
			if(q[i][j]!='<')a.push_back(q[i][j]);
		}
		s.push_back(a);
	}
	for(int i=0;i<s.size();i++){
		int k=0;
		for(int j=0;j<s[i].size()&&k<r[i].size();j++,k++){
			if(s[i][j]==r[i][j])ans++;
		}
	}
	double an=(double)ans/(t/60.0);
	cout<<(int)(an+0.5)<<endl;
	return 0;
}
