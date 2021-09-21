#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("LICH.INP","r",stdin);
	freopen("LICH.OUT","w",stdout);
	int n; cin>>n;
	vector<pair<int,int>> A;
	for(int i = 0; i < n; ++i){
		int a,b; cin>>a>>b;
		A.push_back({a,b});
	}
	sort(A.begin(),A.end());
	set<pair<int,int>> S;
	S.insert({A[0].second,1});
	vector<int> ans;
	for(int i = 1; i < n; ++i){
		int temp = (*prev(S.end())).first;
		if(A[i].first >= temp){
			S.insert({A[i].second,i + 1});
		}else{
			if(A[i].second < temp){
				S.erase(*prev(S.end()));
				S.insert({A[i].second,i + 1});
			}
		}
	}
	cout<<(int)S.size();
	if((int)S.size()) cout<<"\n";
	for(set<pair<int,int>>::iterator it = S.begin(); it != S.end(); ++it){
		cout<<(*it).second;
		it == prev(S.end()) ? cout<<"" : cout<<" ";
	}
}