#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6;
vector<tuple<int,int,int>> adj;
vector<int> djs(M), len(M,1);
int find(int a){
	while(djs[a] != a){
		a = djs[a];
	}
	return a;
}
void join(int x, int y){
	int a = find(x), b = find(y);
	if(len[a] > len[b]){
		swap(a,b);
	}
	djs[a] = b;
	len[b] = len[a] + len[b];
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BTS.INP","r",stdin);
	freopen("BTS.OUT","w",stdout);
	int n; cin>>n;
	for(int i = 0; i < M; ++i){
		djs[i] = i;
	}
	vector<pair<int,int>> A, B; 
	for(int i = 0; i < n; ++i){
		int a,b; cin>>a>>b;
		A.push_back({a,i + 1});
		B.push_back({b,i + 1});
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	for(int i = 0; i < (int)A.size() - 1; ++i){
		int a1 = A[i].first , node1 = A[i].second;
		int a2 = A[i + 1].first , node2 = A[i + 1].second;
		adj.push_back({abs(a1 - a2),node1,node2});
		a1 = B[i].first; node1 = B[i].second;
		a2 = B[i + 1].first; node2 = B[i + 1].second;
		adj.push_back({abs(a1 - a2),node1,node2});
	}
	sort(adj.begin(),adj.end());
	int ans = 0;
	for(int i = 0; i < (int)adj.size(); ++i){
		int a,b,c; tie(c,a,b) = adj[i];
		if(find(a) != find(b)){
			ans += c;
			join(a,b);
		}
	}
	cout<<ans;
}