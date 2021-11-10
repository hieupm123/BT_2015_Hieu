#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mx = 1e6 + 5;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("THAYTHE.INP","r",stdin);
	freopen("THAYTHE.OUT","w",stdout);
	int n,p,a,b,r; cin>>n>>p>>a>>b>>r;
	queue<pair<int,int>> adj; adj.push({0,n});
	vector<int> vis(Mx);
	while(!adj.empty()){
		int res = adj.front().first;
		int node = adj.front().second;
		adj.pop();
		if(vis[node]) continue;
		if(node == r){
			cout<<res;
			return 0;
		}
		vis[node] = 1;
		int num1 = (node + a) % p;
		int num2 = (node + b) % p;
		int num3 = (node + a + b) % p;
		if(!vis[num1]){
			adj.push({res + 1,num1});
		}
		if(!vis[num2]){
			adj.push({res + 1,num2});
		}
		if(!vis[num3]){
			adj.push({res + 1,num3});
		}
	}
	cout<<-1;
}
