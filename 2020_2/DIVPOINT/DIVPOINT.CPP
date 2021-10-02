#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X real()
#define Y imag()
#define double long double
const int M = 0, inf = 1e18;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("DIVPOINT.INP","r",stdin);
	freopen("DIVPOINT.OUT","w",stdout);
	int n; cin>>n;
	vector<pair<int,int>> adj;
	int x = inf, y = inf; 
	for(int i = 0; i < n; ++i){
		int a,b; cin>>a>>b;
		adj.push_back({a + M,b + M});
		if(b + M < y){
			y = b + M;
			x = a + M;
		}else if(b + M == y){
			x = min(a + M,x);
		}
	}
	vector<pair<double,pair<int,int>>> rad;
	for(int i = 0; i < (int)adj.size(); ++i){
		int a = adj[i].first;
		int b = adj[i].second;
		if(a == x && b == y) continue;
		complex<double> vt; vt = {(double)a - x,(double)b - y};
		rad.push_back({(double)arg(vt),{a,b}});
	}
	sort(rad.begin(),rad.end());
	n = (int)rad.size();
	cout<<x<<" "<<y<<" "<<rad[n / 2].second.first<<" "<<rad[n / 2].second.second;
}