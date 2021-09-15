#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("TREELINE.INP","r",stdin);
	// freopen("TREELINE.OUT","w",stdout);
	int n,h; cin>>n>>h;
	vector<int> adj(n);
	for(int i = 0; i < n; ++i) cin>>adj[i];
	int cnt1 = 0;
	for(int i = 0; i < n - 1; ++i){
		if(adj[i] < adj[i + 1]) ++cnt1;
	}
	cnt1 += 2;
	cout<<cnt1<<"\n";
	adj.push_back(h);
	sort(adj.begin(),adj.end());
	

}