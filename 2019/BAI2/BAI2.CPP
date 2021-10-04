#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI2.INP","r",stdin);
	freopen("BAI2.OUT","w",stdout);
	int a,b,k; cin>>a>>b>>k;
	k -= 10;
	if(k == 0){
		if(b == 0){
			cout<<a * 100;
		}
		return 0;
	}
	for(int i = 2; i <= 17; ++i){
		int e = a * pow(10,i) + b;
		if(e % k == 0){
			cout<<e / k;
			return 0; 
		}
	}
}