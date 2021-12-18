#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("SUMN.INP","r",stdin);
	freopen("SUMN.OUT","w",stdout);
	string s; cin>>s;
	int ans = 0;
	for(int i = 0; i < (int)s.size(); ++i){
		ans += s[i] - '0';
	}
	cout<<ans;
}