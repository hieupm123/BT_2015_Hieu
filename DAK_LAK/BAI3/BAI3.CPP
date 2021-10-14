#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int Mx = 505;
vector<vector<int>> adj(Mx,vector<int>(Mx,inf)), pa(Mx,vector<int>(Mx)), per;
int ans = inf;
void recur(vector<int> A, vector<int> res){
	if(res.size() == 4){
		vector<int> tmp;
		for(auto i : res){
			tmp.push_back(i);
		}
		per.push_back(tmp);
		res.clear();
		return;
	}
	for(int i = 0; i < (int)A.size(); ++i){
		if(find(res.begin(),res.end(),A[i]) == res.end()){
			res.push_back(A[i]);
			recur(A,res);
			res.pop_back();
		}
	}
}
void check(set<pair<int,int>> &lis,int l, int r){
	int mid = pa[l][r];
	if(mid && l != r){
		if(lis.find({l,mid}) == lis.end() && lis.find({mid,l}) == lis.end()){
			lis.insert({l,mid});
		}
		if(lis.find({r,mid}) == lis.end() && lis.find({mid,r}) == lis.end()){
			lis.insert({mid,r});
		}
		check(lis,l,mid);
		check(lis,mid,r);
	}else if(!mid && l != r){
		if(lis.find({l,r}) == lis.end() && lis.find({r,l}) == lis.end()){
			lis.insert({l,r});
		}
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI3.INP","r",stdin);
	freopen("BAI3.OUT","w",stdout);
	int n; cin>>n;
	vector<int> A; map<int,int> Cnt;
	for(int i = 0; i < 4; ++i){
		int a; cin>>a; A.push_back(a);
		Cnt[a]++;
	}
	vector<int> B;
	recur(A,B);
	int a,b,c;
	while(cin>>a>>b>>c){
		adj[a][b] = adj[b][a] = min(adj[a][b],c);
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			for(int k = 1; k <= n; ++k){
				if(adj[j][k] > adj[j][i] + adj[i][k]){
					adj[j][k] = adj[j][i] + adj[i][k];
					pa[j][k] = i;
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		adj[i][i] = 0;
	}
	int ans = inf; 
	set<pair<int,int>> sans;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			for(int k = 0; k < (int)per.size(); ++k){
				vector<int> tmp = per[k];
				int res = 0;
				set<pair<int,int>> restmp;
				res = adj[i][tmp[0]] + adj[i][tmp[1]] + adj[j][tmp[2]] + adj[j][tmp[3]] + adj[i][j];
				if(ans > res){
					ans = min(ans,res);
					check(restmp,i,tmp[0]);
					check(restmp,i,tmp[1]);
					check(restmp,j,tmp[2]);
					check(restmp,j,tmp[3]);
					check(restmp,i,j);
					sans = restmp;
				}
			}
		}
	}
	cout<<ans<<"\n";
	for(pair<int,int> i : sans){
		cout<<i.first<<" "<<i.second<<"\n";
	}
}