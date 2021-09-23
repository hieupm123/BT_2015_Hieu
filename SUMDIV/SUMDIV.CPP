#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("SUMDIV.INP","r",stdin);
	freopen("SUMDIV.OUT","w",stdout);
	int L,R; cin>>L>>R;
	int ans = 0;
	for(int i = 1; i < L; ++i){
		int a = R / i;
		if(a * i <= R && a * i >= L){
			ans += i;
		}
	}
	ans += ((R + L)*(R - L + 1) )/ 2;
	cout<<ans;

}