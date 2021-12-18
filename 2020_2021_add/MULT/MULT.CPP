#include<bits/stdc++.h>
using namespace std;
#define int long long
void test_case(){
	int n,x; cin>>n>>x;
	int pre = x / n;
	if(pre < 1){
		cout<<0;
		return;
	}
	cout<<pre - 1 + 1;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("MULT.INP","r",stdin);
	freopen("MULT.OUT","w",stdout);
	int t; cin>>t;
	for(int i = 0; i < t; ++i){
		test_case();
		i == t - 1 ? cout<<"" : cout<<"\n";
	}
}