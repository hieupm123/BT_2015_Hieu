// Vũ Minh Hiếu
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI1.INP","r", stdin);
	freopen("BAI1.OUT","w",stdout);
	int n; cin>>n;
	set<int> S;
	map<int,int> unm;
	vector<int> adj(n);
	int ans = -inf;
	for(int i = 0; i < n; ++i){
		cin>>adj[i];
		S.insert(adj[i]);
	}
	for(int i = 0; i < n - 1; ++i){
		if(!unm[adj[i]]){
			ans = max(ans,*prev(S.end()) - adj[i]);
			S.erase(adj[i]);
			unm[adj[i]] = 1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
