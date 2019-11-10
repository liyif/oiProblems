#include<bits/stdc++.h>
using namespace std;
string s[110];
int n,m,k;
int ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=0;j<s[i].size();j++)
			if(s[i][j]>='A'&&s[i][j]<='Z')s[i][j]+='a'-'A';
	}
	string rs[1010];
	int i=0;
	int  c=getchar();
	while(c=='\n'||c=='\r')c=getchar();
	while(c!='\n'&&c!='\r'&&c!=EOF){
		if(c>='a'&&c<='z')rs[i].push_back(c);
		else {
			if(c>='A'&&c<='Z')rs[i].push_back(c-'A'+'a');
			else {
				if(c=='.'){
					for(int j=1;j<=n;j++){
						for(int k=0;k<=i;k++)
							if(s[j]==rs[k]){
								ans++;
								break;
							}
					}
					for(int k=0;k<=i;k++)
						rs[k]="";
				}
				else i++;
			}
		}
		c=getchar();
	}
	cout<<ans<<endl;
	return 0;
}
