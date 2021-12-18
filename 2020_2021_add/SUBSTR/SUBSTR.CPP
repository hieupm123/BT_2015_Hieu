#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mx = 2e6;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("SUBSTR.INP","r",stdin);
	freopen("SUBSTR.OUT","w",stdout);
	int k; cin>>k;
	string s; cin>>s;
	vector<int> pre(Mx), suff(Mx), adj;
	int cnt = 1;
	for(int i = 0; i < (int)s.size(); ++i){
		if(s[i] == '0'){
			++cnt;
		}else{
			pre[i + 1] = cnt;
			cnt = 1;
			adj.push_back(i + 1);
		}
	}
	cnt = 1;
	for(int i = (int)s.size() - 1; i >= 0; --i){
		if(s[i] == '0'){
			++cnt;
		}else{
			suff[i + 1] = cnt;
			cnt = 1;
		}
	}
	int ans = 0;
	for(int i = 0; i < (int)adj.size(); ++i){
		int a = adj[i];
		if(i + k - 1 < (int)adj.size()){
			int b = adj[i + k - 1];
			ans = ans + pre[a] * suff[b];
		}
	}
	cout<<ans;
}