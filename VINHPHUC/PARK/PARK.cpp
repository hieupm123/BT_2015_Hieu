#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mx = 1e5 + 5;
vector<int> adj[Mx];
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("PARK.INP","r",stdin);
	freopen("PARK.OUT","w",stdout);
	int n,m; cin>>n>>m;
	for(int i = 0; i < m; ++i){
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> A;
	for(int i = 0; i < (int)adj[1].size(); ++i){
		A.push_back(adj[1][i]);
	}
	vector<int> ans(Mx);
	for(int i = 0; i < (int)A.size(); ++i){
		int a = A[i];
		for(int j = 0; j < (int)adj[a].size(); ++j){
			int b = adj[a][j];
			if(b != 1 && b != a){
				ans[b]++;
			}
		}
	}
	int res = 0;
	for(int i = 2; i <= n; ++i){
		if(ans[i] >= 2){
			res += ans[i] * (ans[i] - 1);
		}
	}
	cout<<res;
}