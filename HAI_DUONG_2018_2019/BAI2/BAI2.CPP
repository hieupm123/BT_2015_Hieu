#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin>>n;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		double a; cin>>a;
		if((int)a == 10){
			++ans;
		}
	}
	cout<<ans;
}