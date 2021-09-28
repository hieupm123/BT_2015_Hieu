#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e7;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI2.INP", "r",stdin);
	freopen("BAI2.OUT","w",stdout);
	int tmp = 0;
	string s; cin>>s;
	vector<int> A(10);
	for(int i = 0; i < (int)s.size(); ++i){
		tmp += s[i] - '0';
		A[s[i] - '0']++;
	}
	if(!A[0]){
		cout<<-1;
		return 0;
	}
	s = "";
	for(int i = 9; i >= 0; --i){
		string a(A[i],(i + '0'));
		s += a;
	}
	(tmp % 3) ? cout<<-1 : cout<<s;
}