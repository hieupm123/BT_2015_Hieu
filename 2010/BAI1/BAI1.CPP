#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI1.INP","r",stdin);
	freopen("BAI1.OUT","w",stdout);
	int n, lcm; cin>>n;
	vector<int> adj(n);
	for(int i = 0; i < n; ++i){
		cin>>adj[i];
	}
	lcm = adj[0];
	for(int i = 1; i < n; ++i){
		lcm = (lcm * adj[i]) / __gcd(lcm,adj[i]);
	}
	// O(nlog(2m))
	cout<<lcm;
}