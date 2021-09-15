#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e18;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BONUS.INP","r",stdin);
	freopen("BONUS.OUT","w",stdout);
	int n,k; cin>>n>>k;
	vector<vector<int>> tb(1100,vector<int>(1100,0));
	for(int i = 1; i <= n; ++i){
		int temp = 0;
		for(int j = 1; j <= n; ++j){
			int a; cin>>a;
			temp += a;
			tb[i][j] = tb[i - 1][j] + temp;
		}
	}
	int ans = -inf;
	for(int i = 1; i + k  - 1 <= n; ++i){
		for(int j = 1; j + k - 1 <= n; ++j){
			int x1 = i, x2 = i + k - 1, y1 = j, y2 = j + k - 1;
			ans = max(ans,tb[x2][y2] - tb[x2][y1 - 1] - tb[x1 - 1][y2] + tb[x1 - 1][y1 - 1]);
		}
	}
	cout<<ans;
	
}