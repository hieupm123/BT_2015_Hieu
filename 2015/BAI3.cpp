// Vũ Minh Hiếu
#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans = 0;
void process(vector<pair<int,int>> adj){
	map<pair<int,int>,int> M;
	unordered_map<int,int> T1, T2;
	for(int i = 0; i < (int)adj.size(); ++i){
		int a = adj[i].first, b = adj[i].second;
		M[adj[i]]++;
		T1[a]++; T2[b]++;
	}
	for(int i = 0; i < (int)adj.size(); ++i){
		int a = adj[i].first, b = adj[i].second;
		ans += T1[a] - M[adj[i]];
		ans += T2[b] - M[adj[i]];
		M[adj[i]]--; T1[a]--; T2[b]--;
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI3.INP","r",stdin);
	freopen("BAI3.OUT","w",stdout);
	int n; cin>>n;
	vector<pair<int,int>> adj1,adj2;
	for(int i = 0; i < n; ++i){
		int a,b,c; cin>>a>>b>>c;
		c == 1 ? adj1.push_back({a,b}) : adj2.push_back({a,b});
	}
	process(adj1);
	process(adj2);
	cout<<ans<<"\n";
}