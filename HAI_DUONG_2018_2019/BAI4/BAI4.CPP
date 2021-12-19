#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mx = 1e6 + 1;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI4.INP","r",stdin);
	freopen("BAI4.OUT","w",stdout);
	int n,d; cin>>n>>d;
	vector<vector<int>> adj(Mx);
	vector<int> vt;
	vector<int> dp(Mx);
	for(int i = 0; i < n; ++i){
		int a; cin>>a;
		adj[a].push_back(i + 1);
		vt.push_back(a);
	}
	int ans = 0;
	for(int i = 0; i < (int)vt.size(); ++i){
		if(dp[i + 1]){
			continue;
		}
		dp[i + 1] = 1;
		ans = max(ans,dp[i + 1]);
		int pre = i + 1;
		int val = vt[i] + d;
		vector<int>::iterator it;
		if((int)adj[val].size()){
			it = upper_bound(adj[vt[i] + d].begin(),adj[vt[i] + d].end(),i + 1);
		}else{
			continue;
		}
		while(it != adj[val].end()){
			if(dp[pre] + 1 > dp[*it]){
				dp[*it] = dp[pre] + 1;
				ans = max(ans,dp[*it]);
			}else{
				break;
			}
			val = val + d;
			pre = *it;
			if((int)adj[val].size()){
				it = upper_bound(adj[val].begin(),adj[val].end(),pre);
			}else{
				break;
			}
		}
	}
	cout<<ans;

}