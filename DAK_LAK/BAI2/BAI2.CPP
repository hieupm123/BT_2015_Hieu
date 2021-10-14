#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<vector<int>>> pre(10,vector<vector<int>>(10));
int check_index(int l, int r, vector<string> adj){
	for(int i = 0; i < 9; ++i){
		if(adj[l][r] == adj[l][i] && i != r){
			return 0;
		}
	}
	for(int i = 0; i < 9; ++i){
		if(adj[l][r] == adj[i][r] && i != l){
			return 0;
		}
	}
	int a = l / 3, b = r / 3;
	for(int i = a * 3; i < a * 3 + 3; ++i){
		for(int j = b * 3; j < b * 3 + 3; ++j){
			if(adj[l][r] == adj[i][j] && i != l && j != r){
				return 0;
			}
		}
	}
	return 1;
}
int ok = 0;
void recur(vector<pair<int,int>> Q,vector<string> adj, int cnt){
	if(ok) return;
	if(!cnt){
		for(int i = 0; i < 9; ++i){
			for(int j = 0; j < 9; ++j){
				cout<<adj[i][j];
			}
			i == 8 ? cout<<"" : cout<<"\n";
		}
		ok = 1;
		return;
	}
	pair<int,int> tmp = Q.back();
	for(int i = '1'; i <= '9'; ++i){
		Q.pop_back();
		adj[tmp.first][tmp.second] = i;
		if(check_index(tmp.first,tmp.second,adj)){
			recur(Q,adj,cnt - 1);
		}
		adj[tmp.first][tmp.second] = '.';
		Q.push_back(tmp);
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI2.INP","r",stdin);
	freopen("BAI2.OUT","w",stdout);
	vector<string> adj;
	for(int i = 0; i < 9; ++i){
		string a; cin>>a; adj.push_back(a);
	}
	int cnt = 0;
	vector<pair<int,int>> Q;
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			if(adj[i][j] == '.'){
				Q.push_back({i,j});
				for(int a = '1'; a <= '9'; ++a){
					adj[i][j] = a;
					if(check_index(i,j,adj)){
						pre[i][j].push_back(a);
					}
					adj[i][j] = '.';
				}
				++cnt;
			}
		}
	}
	recur(Q,adj,cnt);
	if(ok == 0) cout<<"That bai";
}