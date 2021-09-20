#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 500;
vector<vector<int>> adj(M,vector<int>(M));
vector<int> tox = {-1,-1,-1,0,0,1,1,1}, toy = {-1,0,1,1,-1,-1,0,1};
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI3.INP","r",stdin);
	freopen("BAI3.OUT","w",stdout);
	int n,m,k; cin>>n>>m>>k;
	for(int i = 0; i < k; ++i){
		int a,b; cin>>a>>b;
		adj[a][b] = 1;
		for(int j = 0; j < 8; ++j){
			adj[a + tox[j]][b + toy[j]] = 1;
		}
	}
	vector<pair<int,int>> ans;
	for(int i = 1; i <= 2; ++i){
		for(int j = 1; j <= 2; ++j){
			vector<pair<int,int>> temp;
			for(int a = i; a <= n; a += 2){
				for(int b = j; b <= m; b += 2){
					if(!adj[a][b]){
						temp.push_back({a,b});
					}
				}
			}
			if((int)ans.size() < (int)temp.size()){
				ans = temp;
			}
		}
	}
	cout<<(int)ans.size();
	for(int i = 0; i < (int)ans.size(); ++i){
		cout<<"\n"<<ans[i].first<<" "<<ans[i].second;
	}

}