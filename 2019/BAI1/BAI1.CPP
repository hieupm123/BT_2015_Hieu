#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e15;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI1.INP","r",stdin);
	freopen("BAI1.OUT","w",stdout);
	int n; cin>>n;
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		int a = (n / i) * 2;
		if(a < i){
			break;
		}
		if(i % 2){
			if(n % i == 0){
				ans++;
			}
		}else{
			if(n % i == (i / 2)){
				++ans;
			}
		}
	}
	cout<<ans;

}