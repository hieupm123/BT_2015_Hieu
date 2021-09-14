#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> tox = {1,-1,0,0}, toy = {0,0,1,-1};
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI2.INP","r",stdin);
	freopen("BAI2.OUT","w",stdout);
	int n,m; cin>>n>>m;
	vector<vector<int>> adj(n + 100,vector<int>(m + 100)), vis(n + 100,vector<int>(m + 100)), pa(n + 100,vector<int>(m + 100));
	int x1,y1,x2,y2;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin>>adj[i][j];
			if(adj[i][j] == 2){
				x1 = i;
				y1 = j;
			}else if(adj[i][j] == 3){
				x2 = i;
				y2 = j;
			}
		}
	}
	queue<pair<int,int>> Q;
	Q.push({x1,y1});
	vis[x1][y1] = 1;
	while(!Q.empty()){
		auto a = Q.front();
		Q.pop();
		vis[a.first][a.second] = 1;
		for(int i = 0; i < 4; ++i){
			int x = a.first + tox[i];
			int y = a.second + toy[i];
			if(x < n && y < m && x >= 0 && y >= 0 && !vis[x][y] && adj[x][y] != 1){
				Q.push({x,y});
				vis[x][y] = 1;
				pa[x][y] = i;
			}
		}
	}
	vector<pair<int,int>> ans;
	pair<int,int> run = {x2,y2};
	while(run != make_pair(x1,y1)){
		ans.push_back(run);
		auto temp = run;
		run.first -= tox[pa[temp.first][temp.second]];
		run.second -= toy[pa[temp.first][temp.second]];
	}
	ans.push_back({x1,y1});
	cout<<(int)ans.size()<<"\n";
	reverse(ans.begin(),ans.end());
	for(int i = 0; i < (int)ans.size(); ++i){
		cout<<ans[i].first + 1<<" "<<ans[i].second + 1;
		(i == (int)ans.size() - 1) ? cout<<"" : cout<<"\n";
	}
	return 0;
}