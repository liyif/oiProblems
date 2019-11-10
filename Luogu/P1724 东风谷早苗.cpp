#include<bits/stdc++.h>
using namespace std;
string s;
long long t;
long long ax,ay,bx,by;
int main(){
	cin>>s;
	cin>>t;
	for(long long i=0;i<s.size();i++){
		if(s[i]=='W')ax--;
		else if(s[i]=='E')ax++;
			else if(s[i]=='N')ay++;
				else ay--;
	}
	bx=ax*(t/s.size());
	by=ay*(t/s.size());
	for(long long i=0;i<t%s.size();i++){
		if(s[i]=='W')bx--;
		else if(s[i]=='E')bx++;
			else if(s[i]=='N')by++;
				else by--;
	}
	cout<<bx<<" "<<by<<endl;
	return 0;
}
