#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("ZERO.INP","r",stdin);
	freopen("ZERO.OUT","w",stdout);
	map<int,int> mp;
	int n; cin>>n;
	vector<int> pre(n + 100);
	for(int i = 1; i <= n; ++i){
		int a; cin>>a;
		pre[i] = pre[i - 1] + a;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		if(!pre[i]){
			ans = max(ans,i);
		}
		int check = mp[pre[i]];
		if(check){
			ans = max(ans,i - check);
		}else{
			mp[pre[i]] = i;
		}
	}
	cout<<ans;
}