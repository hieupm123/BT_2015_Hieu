#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mx = 10;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("SOTRANG.INP","r",stdin);
	freopen("SOTRANG.OUT","w",stdout);
	int n; cin>>n;
	int run_end = 9, run_st = 1;
	int ans = 0;
	if(n <= 6){
		int b = n;
		ans = 4 + b - 1;
		cout<<ans;
		return 0;
	}
	n -= 6;
	for(int i = 2; i < Mx; ++i){
		run_end = run_end * 10 + 9;
		run_st = run_st * 10;
		int a = (run_end - run_st + 1) * i;
		if(n > a){
			n -= a;
		}else if(n < a){
			int b = n / i;
			ans = run_st + b - 1;
			break;
		}
	}
	cout<<ans;
}
