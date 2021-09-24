#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("SUMDIV.INP","r",stdin);
	freopen("SUMDIV.OUT","w",stdout);
	int L, R; cin>>L>>R;
	int tmp = 0, ans = 0, check = sqrt(R) + 1;
	vector<pair<int,pair<int,int>>> vis;
	for(int i = 1; i * i <= R; ++i){
		int a = (L + i  - 1) / i;
		int b = R / i;
		if(b - a >= 0){
			vis.push_back({i,{max(a,check),b}});
		}
	}
	reverse(vis.begin(),vis.end());
	for(int i = 0; i < (int)vis.size(); ++i){
		int a = vis[i].first;
		int b = max(tmp,vis[i].second.first);
		int c = vis[i].second.second;
		ans += a;
		if(c - b >= 0){
			ans += (c + b) * (c - b + 1) / 2;
			tmp = c + 1;
		}

	}
	cout<<ans;
}