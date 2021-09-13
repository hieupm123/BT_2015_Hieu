// Vũ Minh Hiếu
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI3.INP","r",stdin);
	freopen("BAI3.OUT","w",stdout);
	int n,k; cin>>n>>k;
	vector<int> unm(n);
	for(int i = 0; i < n; ++i){
		int a,b; cin>>a>>b;
		unm[i] = (b - a + 1);
	}
	int L = 1, R = inf, ans = 0;
	while(L <= R){
		int mid = (L + R) / 2;
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			cnt += (int)(unm[i] / mid);
		}
		if(cnt >= k){
			ans = mid;
			L = mid + 1;  
		}
		else{
			R = mid - 1;
		}
	}
	cout<<ans<<"\n";

}