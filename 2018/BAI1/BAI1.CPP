#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6 + 1000, inf = 1e18;
vector<int> pre(M), sprime;
void stev(){
	pre[1] = 1;
	pre[0] = 1;
	for(int i = 2; i < M; ++i){
		if(!pre[i]){
			for(int j = i + i; j < M; j += i){
				pre[j] = 1;
			}
			sprime.push_back(i);
		}
	}
}
void test_case(){
	int ans = -inf;
	int n; cin>>n;
	int i = 0;
	for(i; sprime[i] * sprime[i + 1] * sprime[i + 2] <= n; ++i){
		int b = sprime[i] * sprime[i + 1] * sprime[i + 2];
		if(b <= n){
			ans = max(ans,b);
		}
	}
	cout<<ans;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI1.INP","r",stdin);
	freopen("BAI1.OUT","w",stdout);
	stev();
	int t; cin>>t;
	for(int i = 0; i < t; ++i){
		test_case();
		i == t - 1 ? cout<<"" : cout<<"\n";
	}


}