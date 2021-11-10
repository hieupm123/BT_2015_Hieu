#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mx = 1e9 + 9, inf =1e18;
pair<int,int> bn1(int m, int n, int sum){
	int l = 1, r = n;
	int run = inf, ans = inf;
	while(l <= r){
		int mid = (l + r) / 2;
		if(mid == 1){
			break;
		}
		int col1 = ((1 + 1 + n * (m - 1)) * m) / 2;
		int col2 = ((mid - 1 + mid - 1 + n * (m - 1)) * m) / 2;
		int s1 = (col2 + col1) * (mid - 1) / 2;
		int s2 = sum - s1;
		// cout<<mid<<" "<<s1<<" "<<s2<<"\n";
		if(abs(s2 - s1) < run){
			run = abs(s2 - s1);
			ans = mid;
		}
		if(s2 >= s1){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return make_pair(ans,run);
}
pair<int,int> bn2(int m, int n, int sum){
	int l = 1, r = m;
	int run = inf, ans = inf;
	while(l <= r){
		int mid = (l + r) / 2;
		if(mid == 1){
			break;
		}
		int s1 = (1 + (mid - 1) * n) * ((mid - 1) * n) / 2;
		int s2 = sum - s1;
		// cout<<mid<<" "<<s1<<" "<<s2<<"\n";
		if(abs(s2 - s1) < run){
			run = abs(s2 - s1);
			ans = mid;
		}
		if(s2 >= s1){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return make_pair(ans,run);
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("TABLE.INP","r",stdin);
	freopen("TABLE.OUT","w",stdout);
	int q; cin>>q;
	for(int i = 0; i < q; ++i){
		int m,n; cin>>m>>n;
		int ans = inf;
		int sum = (1 + m * n) * (m * n) / 2;
		pair<int,int> a = bn1(m,n,sum);
		pair<int,int> b = bn2(m,n,sum);
		a.second >= b.second ? cout<<"H"<<" "<<b.first : cout<<"V "<<a.first;
		i == q - 1 ? cout<<"" : cout<<"\n";
	}
}