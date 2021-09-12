#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
vector<int> tox = {1,-1,0,0}, toy = {0,0,1,-1}; 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI4.INP","r",stdin);
	freopen("BAI4.OUT","w",stdout);
	int n,m; cin>>n>>m;
	int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
	--x1;--y1;--x2;--y2;
	int adj[110][110]; 
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin>>adj[i][j];
		}
	}
	vector<vector<int>> ans(110, vector<int>(110, inf));
	priority_queue<pair<int,pair<int,int>>> pq;
	ans[x1][y1] = 0;
	pq.push({0,{x1,y1}});
	vector<vector<int>> vis(110,vector<int>(110));
	while(!pq.empty()){
		pair<int,int> node = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if(vis[node.first][node.second]) continue;
		vis[node.first][node.second] = 1;
		for(int i = 0; i < 4; ++i){
			int a = node.first + tox[i];
			int b = node.second + toy[i];
			if(a < n && b < m && a >= 0 && b >= 0){
				int temp = max(ans[node.first][node.second],abs(adj[a][b] - adj[node.first][node.second]));
				if(ans[a][b] > temp){
					ans[a][b] = temp;
					pq.push({-temp,{a,b}});
				}
			}
		}
	}
	cout<<ans[x2][y2]<<"\n";


}