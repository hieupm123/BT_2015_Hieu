#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[402][402][16];
vector<vector<int>> adj(500,vector<int>(500));
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("COLOREC.INP","r",stdin);
	freopen("COLOREC.OUT","w",stdout);
	int n; cin>>n;
	for(int i = 0; i < n; ++i){
		int a,b,c; cin>>a>>b>>c;
		adj[a + 201][b + 201] = c;
	}	
	for(int i = 0; i < 402; ++i){
		for(int j = 0; j < 402; ++j){
			for(int k = 0; k < 16; ++k){
				dp[i][j][k] = 0;
			}
		}
	}
	for(int i = 1; i <= 401; ++i){
		for(int j = i + 1; j <= 401; ++j){
			for(int k = 1; k <= 401; ++k){
				if(adj[i][k] && adj[j][k] && adj[i][k] != adj[j][k]){
					dp[i][j][(1 << (adj[i][k] - 1)) + (1 << (adj[j][k] - 1))]++;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= 401; ++i){
		for(int j = 1; j <= 401; ++j){
			for(int k = 0; k < 16; ++k){
				ans += dp[i][j][k] * dp[i][j][15 - k];
			}
		}
	}
	ans /= 2;
	cout<<ans;
}