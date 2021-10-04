#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI2.INP","r",stdin);
	freopen("BAI2.OUT","w",stdout);
	int m,n; cin>>m>>n;
	vector<int> A(m),B(n);
	for(int i = 0; i < m; ++i){
		cin>>A[i];
	}
	for(int i = 0; i < n; ++i){
		cin>>B[i];
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int ans = 0;
	for(int i = 0, j = 0; i < m, j < m;){
		if(A[i] > B[j]){
			++ans;
			++i; ++j;
		}else{
			++j;
		}
	}
	cout<<ans;
}