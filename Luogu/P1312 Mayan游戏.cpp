#include<bits/stdc++.h>
#define D_DEBUG__
using namespace std;
const int maxLen=5;
const int maxHig=7;
int n;
//int m[10][10];
int d[10][10][8];
struct step{
	int x,y,z;
};
vector<step>vec;
int p1[10][10],p2[10][10];
void read(int &x){
	x=0;
	char c;
	fread(&c,1,1,stdin);
	while(c<'0'&&c>'9')fread(&c,1,1,stdin);
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		fread(&c,1,1,stdin);
	}
}
void input(){
	read(n);
	for(int i=0;i<maxLen;i++){
		int j=0,k;
		read(k);
		while(k!=0){
			d[j][i][0]=k;
			j++;
			read(k);
		}
	}
}
void down(int dep,int x){
	for(int i=1;i<maxHig;++i){
		int j;
		for(j=i-1;j>=0&&d[j][x][dep]==0;--j);
		j++;
		swap(d[j][x][dep],d[i][x][dep]);
	}
}
bool erase(int dep){
	for(int i=0;i<maxHig;i++)
	d[i][0][dep]=1;
	for(int i=0;i<maxLen;i++)
	d[0][i][dep]=1;
} 
bool check(int dep){
	for(int i=0;i<maxLen;i++)
	if(d[0][i][dep]!=0)return 0;
	return 1;
}
void move(int dep,int x,int y,int z){
	for(int i=0;i<maxLen;i++)
	for(int j=0;j<maxHig;j++)
	d[j][i][dep]=d[j][i][dep-1];
	swap(d[y][x][dep],d[y][x+z][dep]);
	down(dep,x);
	down(dep,x+z);
	while(erase(dep));
	//
}
void print(){
	for(int i=0;i<vec.size();i++)
	cout<<vec[i].x<<" "<<vec[i].y<<" "<<vec[i].z<<endl;
}
void dfs(int dep){
	if(check(dep)){
		print();
		exit(0);
	}
	if(dep>n)return;
	for(int i=0;i<maxLen;i++){
		for(int j=0;j<maxHig;j++){
			if(d[j][i][dep]==0)continue;
			if(d[j][i][dep]!=d[j][i+1][dep]){
				move(dep,i,j,1);
				vec.push_back(step{i,j,1});
				dfs(dep+1);
				vec.pop_back();
			}
			if(d[j][i-1][dep]==0){
				move(dep,i,j,-1);
				vec.push_back(step{i,j,1});
				dfs(dep+1);
				vec.pop_back();
			}
		}
	}
}
int main(){
	input();
	#ifdef D_DEBUG__
	for(int i=0;i<maxHig;i++){
		for(int j=0;j<maxLen;j++)
		cout<<d[i][j][0]<<" ";
		cout<<endl;
	}
	//cout<<check(1);
	#endif
	return 0;
}

