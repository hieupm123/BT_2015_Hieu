#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e18;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI3.INP","r",stdin);
	freopen("BAI3.OUT","w",stdout);
	int n,m; cin>>n>>m;
	unordered_set<int> usc;
	unordered_map<int,int> uma;
	for(int i = 0; i < n; ++i){
		int a; cin>>a;
		uma[a]++;
	}
	for(int i = 0; i < m; ++i){
		int a; cin>>a;
		if(uma[a]) usc.insert(a);
	}
	vector<int> C;
	for(unordered_set<int>::iterator it  = usc.begin(); it != usc.end(); ++it){
		C.push_back(*it);
	}
	reverse(C.begin(),C.end());
	cout<<(int)C.size()<<"\n";
	for(auto i : C) cout<<i<<" ";
	cout<<"\n";
	int r = -inf, h;
	for(int i = 1; i <= (int)C.size(); ++i){
		int cnt = 0;
		for(int j = 0; j < (int)C.size(); ++j){
			int temp = C[j];
			temp %= i;
			for(int z = 0; z < i - 1; ++z){
				temp *= C[j];
				temp %= i;
			}
			cnt += temp;
			cnt %= i;
		}
		if(cnt > r){
			r = cnt;
			h = i;
		}
	}
	cout<<h<<" "<<r;
	return 0;
}
