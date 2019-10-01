#include<bits/stdc++.h>
using namespace std;
struct node{
	int edge;
	int next;
};
int n,m;
node ed[200010];
int head[200010];
set<int> mes[200010][2];
void addE(int x,int y){
	ed[m].edge=y;
	ed[m].next=head[x];
	head[x]=m++;
} 

int main(){
	memset(head,-1,sizeof(head));
	cin>>n;
	int a;
	for(int i=1;i<=n;i++){
		cin>>a;
		addE(i,a);
		mes[i][1].insert(i);
	}
	int k=0;
	while(++k){
		for(int i=1;i<=n;i++){
			for(int j=head[i];j!=-1;j=ed[j].next){
				for(auto g=mes[i][k%2].begin();g!=mes[i][k%2].end();g++){
					if(*g!=ed[j].edge){
						mes[j][(k+1)%2].insert(*g); 
					}
					else{
						cout<<k+1<<endl;
						exit(0);
					}
					mes[i][k%2].clear();
				}
			}
		}
	}
	return 0;
}
