#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a,b,c,k,m,n; cin>>a>>b>>c>>k>>m>>n;
	cout<<a * k + b * m + (n - k - m) * c;
}