// Vũ Minh Hiếu
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI1.INP","r", stdin);
	freopen("BAI1.OUT","w",stdout);
	int a,b,c; cin>>a>>b>>c;
	int cnt = 0;
	for(int i = 1; i <= c; ++i){
		int x = (c - b * i)/a;
		if(a * x + b * i == c && x > 0 && __gcd(x,i) == 1) ++cnt;
	}
	cout<<cnt<<"\n";
	return 0;
}