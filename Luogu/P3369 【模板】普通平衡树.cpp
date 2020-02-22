#include<bits/stdc++.h>
using namespace std;

#define LL long long
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int MAXN=1000019,INF=1e9;

int n;
int ch[MAXN][2];
int val[MAXN],dat[MAXN];
int size[MAXN],cnt[MAXN];
int tot,root;
int New(int v){
	val[++tot]=v;
	dat[tot]=rand();
	size[tot]=1;
	cnt[tot]=1;
	return tot;
}
void PushUp(int id){
	size[id]=size[ch[id][0]]+size[ch[id][1]]+cnt[id];
}
void Build(){
	root=New(-INF);
	ch[root][1]=New(INF);
	PushUp(root);
}
void Rotate(int &id,int d){
	int tmp=ch[id][d^1];
	ch[id][d^1]=ch[tmp][d];
	ch[tmp][d]=id;
	id=tmp;
	PushUp(ch[id][d]);
	PushUp(id);
}
void Insert(int &id,int v){
	if(!id){
		id=New(v);
		return;
	}
	if(v==val[id])cnt[id]++;
	else {
		int d=v<val[id]?0:1;
		Insert(ch[id][d],v);
		if(dat[id]<dat[ch[id][d]])Rotate(id,d^1);
	}
	PushUp(id);
}
void Remove(int &id,int v){
	if(!id)return;
	if(v==val[id]){
		if(cnt[id]>1){
			cnt[id]--;
			PushUp(id);
			return;
		}
		if(ch[id][0]||ch[id][1]){
			if(!ch[id][1]||dat[ch[id][0]]>dat[ch[id][1]]){
				Rotate(id,1),Remove(ch[id][1],v);
			}
			else Rotate(id,0),Remove(ch[id][0],v);
			PushUp(id);
		}
		else id=0;
		return;
	}
	if(v<val[id])Remove(ch[id][0],v);
	else Remove(ch[id][1],v);
	PushUp(id);
}
int getRank(int id,int v){
	if(!id)return 0;
	if(v==val[id])return size[ch[id][0]]+1;
	else if(v<val[id])return getRank(ch[id][0],v);
		else return size[ch[id][0]]+cnt[id]+getRank(ch[id][1],v);
}
int getVal(int id,int rank){
	if(!id)return INF;
	if(rank<=size[ch[id][0]])return getVal(ch[id][0],rank);
	else if(rank<=size[ch[id][0]]+cnt[id])return val[id];
		else return getVal(ch[id][1],rank-size[ch[id][0]]-cnt[id]);
}
int getPre(int v){
	int id=root,pre;
	while(id){
		if(val[id]<v)pre=val[id],id=ch[id][1];
		else id=ch[id][0];
	}
	return pre;
}
int getNext(int v){
	int id=root,next;
	while(id){
		if(val[id]>v)next=val[id],id=ch[id][0];
		else id=ch[id][1];
	}
	return next;
}
int main(){
	srand(time(NULL));
	Build();
	n=read();
	for(int i=1;i<=n;i++){
		int opt=read(),x=read();
		switch(opt){
			case 1:
				Insert(root,x);
				break;
			case 2:
				Remove(root,x);
				break;
			case 3:
				cout<<getRank(root,x)-1<<endl;
				break;
			case 4:
				cout<<getVal(root,x+1)<<endl;
				break;
			case 5:
				cout<<getPre(x)<<endl;
				break;
			case 6:
				cout<<getNext(x)<<endl;
		}
	}
	return 0;
}
