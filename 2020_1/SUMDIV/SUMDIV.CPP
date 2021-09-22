#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M =1e6;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("SUMDIV.INP","r",stdin);
	// freopen("SUMDIV.OUT","w",stdout);
	int L,R; cin>>L>>R;
	vector<int> ans(M + 100);
	for(int i = 2; i <= M; ++i){
		for(int j = i; j <= M; j +=i){
			ans[j] += i;
		}
	}
	int res = 0;
	for(int i = L; i <= R; ++i){
		res += ans[i];
	}
	cout<<res;
}