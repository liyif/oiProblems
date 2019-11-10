#include <bits/stdc++.h>
using namespace std;
const int moo=0x3f3f3f3f;
struct sa {
	int deqal;
	int num;
};
int dp[200001];
int x[200001];
deque <sa> deq;
sa tmp;
int n,l,r,q;
int main() {

	cin>>n>>l>>r;
	for(int i=0; i<=n; i++)
		cin>>x[i];
	q=0;
	dp[q]=0;
	for(int i=l; i<=n; i++) {
		while(!deq.empty()&&dp[q]>=deq.back().deqal)deq.pop_back();
		tmp.num=q;
		tmp.deqal=dp[q];
		deq.push_back(tmp);
		if (q-deq.front().num>=(r-l+1))
			deq.pop_front();
		dp[i]=deq.front().deqal+x[i];
		q++;
	}
	int ans=-moo;
	for(int i=n-r+1; i<=n; i++)
		ans=max(ans,dp[i]);
	cout<<ans<<endl;

	return 0;
}
