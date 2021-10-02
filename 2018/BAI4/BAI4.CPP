#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 500, inf = 1e18;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI4.INP","r",stdin);
	freopen("BAI4.OUT","w",stdout);
	vector<vector<int>> adj(M,vector<int>(M)), dp(M,vector<int>(M, inf)), pre(M,vector<int>(M)), add(M,vector<int>(M));
	vector<int> cnt(M);
	int n,m; cin>>n>>m;
	for(int i = 1; i <= n; ++i){
		int a; cin>>a;
		for(int j = 1; j <= a; ++j){
			int b; cin>>b;
			adj[b][i] = 1;
			cnt[b]++;
		}
	}
	for(int i = 1; i <= m; ++i){
		vector<int> tmp(M);
		for(int j = 1; j <= n; ++j){
			if(adj[i][j]) tmp[j]++;
		}
		for(int j = 1; j <= m; ++j){
			if(i == j) continue;
			for(int k = 1; k <= n; ++k){
				if(adj[j][k] && tmp[k]){
					pre[i][j]++;
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			for(int k = 1; k <= m; ++k){
				if(adj[k][i] && adj[k][j] && i != j){
					if(dp[i][j] > cnt[k]){
						dp[i][j] = min(dp[i][j],cnt[k]);
						add[i][j] = k;
					}
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			for(int k = 1; k <= n; ++k){
				if(i == j || k == i || j == k){
					continue;
				}
				if(dp[i][k] != inf && dp[k][j] != inf){
					dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j] - pre[add[i][k]][add[k][j]]);
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		dp[i][i] = 0;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cout<<dp[i][j];
			j == n ? cout<<"" : cout<<" ";
		}
		i == n ? cout<<"" : cout<<"\n";
	}
}