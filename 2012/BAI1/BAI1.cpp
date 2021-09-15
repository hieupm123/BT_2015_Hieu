#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI1.INP","r",stdin);
	freopen("BAI1.OUT","w",stdout);
	bitset<300> bs;
	string s; cin>>s;
	int cnt = 0;
	for(int i = (int)s.size() - 1; i >= 0; --i){
		s[i] == '1' ? bs[cnt] = 1 : bs[cnt] = 0;
		++cnt;
	}
	int value = (int)bs.to_ulong();
	stringstream convert;
	convert << hex << value;
	s = convert.str();
	for(int i = 0; i < (int)s.size(); ++i){
		if(s[i] >= 'a' && s[i] <= 'z'){
			s[i] = s[i] + ('A' - 'a');
		}
	}
	cout<<s;
	return 0;
}
