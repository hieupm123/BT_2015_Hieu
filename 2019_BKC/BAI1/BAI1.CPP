#include<bits/stdc++.h>
using namespace std;
#define int long long
string Y = "CO";
string N = "KHONG";
void test_case(){
	string s; cin>>s;
	int n = (int)s.size();
	if(n == 1){
		cout<<Y;
		return;
	}
	int l = 0, r = n - 1, pv = n / 2;
	while(l < r){
		if(s[l] != s[r]){
			cout<<N;	
			return;
		} 
		++l; --r;
	}
	cout<<Y;

}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI1.INP","r",stdin);
	freopen("BAI1.OUT","w",stdout);
	int n; cin>>n;
	for(int i = 0; i < n; ++i){
		test_case();
		(i == n - 1) ? cout<<"" : cout<<"\n";
	}
}