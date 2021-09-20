#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI2.INP","r",stdin);
	freopen("BAI2.OUT","w",stdout);
	string s; cin>>s;
	int ans = 0;
	for(int i = 0; i < (int)s.size(); ++i){
		for(int j = i + 5; j < (int)s.size(); ++j){
			int c1 = 0,c2 = 0,c3 = 0;
			for(int k = i; k <= j; ++k){
				if(s[k] <= 'Z' && s[k] >= 'A') c1 = 1;
				else if(s[k] <= 'z' && s[k] >= 'a') c2 = 1;
				else if(s[k] >= '0' && s[k] <= '9') c3 = 1;
			}
			if(c1 && c2 && c3) ++ans;
		}
	}
	cout<<ans;
	// O(n ^ 3) n <= 100 => O(n ^ 2) use prefix
}