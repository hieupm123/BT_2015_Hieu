#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6, inf = 1e18;
vector<int> tox = {0,0,1,-1}, toy = {1,-1,0,0};
vector<int> adj[N], vis(N), ans(N, inf);
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<pair<int,int>, int> M;
	freopen("BAI4.INP","r",stdin);
	freopen("BAI4.OUT","w",stdout);
	map<char,int> sw = {{'D',0},{'T',1},{'B',2},{'N',3}};
	int cnt = 2;
	string s; cin>>s;
	int x = 0, y = 0, end = 0;
	M[{x,y}] = 1;
	for(int i = 0; i < (int)s.size(); ++i){
		int prx = x + tox[sw[s[i]]], pry = y + toy[sw[s[i]]];
		if(!M[{prx,pry}]){
			M[{prx,pry}] = cnt;
			++cnt;
		}
		adj[M[{x,y}]].push_back(M[{prx,pry}]);
		adj[M[{prx,pry}]].push_back(M[{x,y}]);
		x = prx; y = pry;
		if(i == (int)s.size() - 1){
			end = M[{x,y}];
		}
	}
	queue<int> Q; Q.push(1); vis[1] = 1; ans[1] = 0;
	while(!Q.empty()){
		int a = Q.front(); Q.pop();
		vis[a] = 1;
		if(a == end){
			cout<<ans[a];
			return 0;
		}
		for(int i = 0; i < (int)adj[a].size(); ++i){
			int b = adj[a][i];
			if(!vis[b]){
				Q.push(b);
				vis[b] = 1;
				ans[b] = min(ans[a] + 1,ans[b]);
			}
		}
	}
	return 0;
}