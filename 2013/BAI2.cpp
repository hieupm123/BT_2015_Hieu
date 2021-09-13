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
	int n,m; cin>>n>>m;
	unordered_map<char,int> swun;
	vector<char> swv = {'D','V','X','T'};  
	for(int i = 0; i < 4; ++i) swun[swv[i]] = i;
	vector<vector<int>> adj(n,vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			char temp; cin>>temp;
			adj[i][j] = swun[temp];
		}
	}
	int dp[250][250][5], ans = -inf, line = inf, car = inf;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			for(int z = 0; z < 3; ++z){
				if(adj[i][j] == 3){
					!j ? dp[i][j][z] = 1 : dp[i][j][z] = dp[i][j - 1][z] + 1;
				}else{
					int check = (z == adj[i][j]);
					if(!check){
						!j ? dp[i][j][z] = 0 : dp[i][j][z] = dp[i][j - 1][z];
						continue;	
					} 
					!j ? dp[i][j][z] = 1 : dp[i][j][z] = dp[i][j - 1][z] + 1; 
				}

				if(dp[i][j][z] > ans){
					ans = dp[i][j][z];
					line = i + 1;
					car = z;
				}else if(dp[i][j][z] == ans){
					if(line == i + 1){
						car = min(car, z);
					}
				}
			}
		}
	}
	cout<<ans<<"\n"<<line<<" "<<swv[car]<<"\n";

	return 0;
}