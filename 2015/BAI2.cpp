// Vũ Minh Hiếu
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e5, inf = 1e18;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI2.INP","r",stdin);
	freopen("BAI2.OUT","w",stdout);
	int n,m; cin>>n;
	vector<int> adj;
	for(int i = 0; i < n; ++i){
		int a; cin>>a;
		adj.push_back(a);
	}
	cin>>m;
	unordered_map<int,int> M;
	for(int i = 0; i < m; ++i){
		int a,b; cin>>a>>b;
		!M[a] ? M[a] = b : M[a] = min(M[a],b);
	}
	vector<int> dp(1010, inf);
	dp[0] = 0;
	for(unordered_map<int,int>::iterator it = M.begin(); it != M.end(); ++it){
		for(int i = 1001; i >= 1; --i){
			(*it).first >= i ? dp[i] = min(dp[i],(*it).second) : dp[i] = min(dp[i],dp[i - (*it).first] + (*it).second);
		}
	}
	int ans = 0;
	for(int i = 0; i < (int)adj.size(); ++i){
		ans += dp[adj[i]];
		// cout<<dp[adj[i]]<<" ";
	}
	cout<<ans<<"\n";
	return 0;
}