#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 9, Mx = 1e5, p = 31;
vector<int> pre(Mx + 100);
vector<int> hashing(string s){
	vector<int> ans((int)s.size() + 100);
	for(int i = 0; i < (int)s.size(); ++i){
		ans[i + 1] = (ans[i] + ((int)s[i] * pre[i] % mod)) % mod;
	}
	return ans;
}
int powmod(int a, int t){
	int ans = 1;
	while(t){
		if(t & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		t /= 2;
	}
	return ans;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s; cin>>s;
	pre[0] = 1;
	for(int i = 1; i <= 500; ++i){
		pre[i] = pre[i - 1] * p % mod;
	}
	vector<int> hash = hashing(s);
	map<int,int> mp;
	int ans = 0;
	for(int i = 1; i <= (int)s.size(); ++i){
		for(int j = i; j <= (int)s.size(); ++j){
			int a = ((hash[j] - hash[i - 1]) * powmod(p,mod - i - 1) + mod) % mod;
			if(!mp[a]){
				++ans;
				mp[a] = 1;
			}
		}
	}
	cout<<ans;
}