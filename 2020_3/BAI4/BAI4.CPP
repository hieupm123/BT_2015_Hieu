#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mx = 1005, inf = 1e18;
const int N = 3e5;
vector<int> tox = {1,-1,0,0}, toy = {0,0,1,-1};
vector<vector<int>> vis(Mx,vector<int>(Mx)), adj(Mx,vector<int>(Mx)), ans(Mx,vector<int>(Mx,inf)); 
vector<pair<int,int>> M[N]; 
map<int,int> hm;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI4.INP","r",stdin);
	freopen("BAI4.OUT","w",stdout);
	int n,m; cin>>n>>m;
	int cnt = 1;
	int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin>>adj[i][j];
			if(adj[i][j] && !hm[adj[i][j]]){
				M[cnt].push_back({i,j});
				hm[adj[i][j]] = cnt;
				++cnt;
			}else if(adj[i][j] && hm[adj[i][j]]){
				M[hm[adj[i][j]]].push_back({i,j});
			}
		}
	}
	queue<pair<int,int>> Q; Q.push({x1,y1});
	vis[x1][y1] = 1; ans[x1][y1] = 0;
	while(!Q.empty()){
		int a = Q.front().first;
		int b = Q.front().second; Q.pop();
		vis[a][b] = 1;
		if(a == x2 && b == y2){
			cout<<ans[x2][y2];
			return 0;
		}
		if(adj[a][b]){
			int c = hm[adj[a][b]];
			vector<pair<int,int>> tmp = M[c];
			while(!tmp.empty()){
				int x = tmp.back().first;
				int y = tmp.back().second;
				if(!vis[x][y]){
					vis[x][y] = 1;
					Q.push({x,y});
					ans[x][y] = min(ans[x][y],ans[a][b] + 1);
				}
				if(x == x2 && y == y2){
					cout<<ans[x2][y2];
					return 0;
				}
				tmp.pop_back();
			}
			M[c] = tmp;
		}
		for(int i = 0; i < 4; ++i){
			int x = a + tox[i];
			int y = b + toy[i];
			if(x <= n && y <= m && x >= 1 && y >= 1 && !vis[x][y] && adj[x][y]){
				vis[x][y] = 1;
				ans[x][y] = min(ans[a][b] + 1,ans[x][y]);
				Q.push({x,y});
			}
		}
	}
	cout<<ans[x2][y2];

}