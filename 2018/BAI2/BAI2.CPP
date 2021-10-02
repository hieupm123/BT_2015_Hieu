#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI2.INP","r",stdin);
	freopen("BAI2.OUT","w",stdout);
	int mn = inf;
	int n; cin>>n;
	vector<int> adj(n);
	for(int i = 0; i < n; ++i){
		cin>>adj[i];
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int a; cin>>a;
		mn = min(mn,a);
		ans += mn * adj[i];
	}
	cout<<ans;
}