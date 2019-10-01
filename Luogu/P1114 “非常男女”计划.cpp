#include<bits/stdc++.h>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		a=(a*10+c-'0');
		c=getchar();
	}
}
int n;
int f[100010];
int a[100010];
int maxn=0;
int main(){
	read(n);
	for(int i=1;i<=n;++i){
		read(f[i]);
		a[i]=a[i-1]+f[i];
	}
	for(int i=1;i<=n-maxn;++i){
		for(int j=i+maxn;j<=n;++j){
			int x=j-i+1;
			if(x==(a[j]-a[i-1])*2&&x>maxn)maxn=x;
		}
		
	}
	cout<<maxn<<endl;
	return 0;
}

