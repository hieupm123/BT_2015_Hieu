#include<bits/stdc++.h>
using namespace std;
#define int long long
string full(string a, map<char,int> b){
	for(int i = '9'; i >= '0'; --i){
		for(int j = 0; j < b[i]; ++j){
			a += i;
		}
	}
	return a;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("SNLN.INP","r",stdin);
	freopen("SNLN.OUT","w",stdout);
	string s, ans = "" , temp = "";; cin>>s;
	map<char,int> M;
	set<char> S; 
	for(int i = 0; i < (int)s.size(); ++i){
		M[s[i]]++;
		S.insert(s[i]);
	}
	for(int i = 0; i < (int)s.size(); ++i){
		if(i == 0 && s[i] == '1') continue;
		map<char,int> MK = M;
		set<char>::iterator it = S.find(s[i]);
		if(it != S.begin()) --it;
		else{
			M[s[i]]--;
			if(!M[s[i]]) S.erase(s[i]);
			temp += s[i];
			continue;
		}
		MK[*it]--;
		ans = full(temp + *it,MK);
		M[s[i]]--;
		if(!M[s[i]]) S.erase(s[i]);
		temp += s[i];
	}
	ans == "" ? cout<<0 : cout<<ans;
}