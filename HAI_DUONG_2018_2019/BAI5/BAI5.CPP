#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mx = 50000, inf = 1e18;
vector<int> pre, vis(Mx);
int n,m;
void eratos(){
	vis[1] = 1; vis[0] = 1;
	for(int i = 2; i <= Mx; ++i){
		if(vis[i]) continue;
		for(int j = i + i; j <= Mx; j += i){
			vis[i] = 1;
		}
		pre.push_back(i);
	}
}
int solove(int a){
	int b = n / a;
	int res = 0, run = 1;
	while((b / run) > 0){
 		res += (int)(b / run);
 		run *= a;
	}
	return res;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI5.INP","r",stdin);
	freopen("BAI5.OUT","w",stdout);
	cin>>n>>m;
	eratos();
	map<int,int> mp;
	vector<int> adj;
	for(int i = 0; i < (int)pre.size(); ++i){
		if(m % pre[i] == 0){
			adj.push_back(pre[i]);
		}
		while(m % pre[i] == 0){
			m /= pre[i];
			mp[pre[i]]++;
		}
	}
	if(m != 1){
		mp[m]++;
	}
	int ans = inf;
	for(int i = 0; i < (int)adj.size(); ++i){
		int a = adj[i];
		ans = min(ans,solove(a) * mp[a]);
	}
	cout<<ans;
}