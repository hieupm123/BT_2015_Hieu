#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
int ans = inf , res = inf;
int l,r;
void recur(int L, int R, int ok , int cnt){
	if(L <= R){
		int mid = (L + R) / 2;
		int a = (mid - l + 1) * (l + mid) / 2;
		int b = (r - mid) * (r + mid + 1) / 2;
		if(ok && abs(a - b) > cnt){
			return;
		}
		if(abs(a - b) < ans){
			ans = abs(a - b);
			res = mid;
			recur(mid + 1,R,0,abs(a - b));
			recur(L,mid - 1,0,abs(a - b));
		}else if(abs(a - b) == ans){
			res = min(res,mid);
			recur(mid + 1,R,0,abs(a - b));
			recur(L,mid - 1,0,abs(a - b));
		}else{
			recur(mid + 1,R,1,abs(a - b));
			recur(L,mid - 1,1,abs(a - b));
		}
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI1.INP","r",stdin);
	freopen("BAI1.OUT","w",stdout);
	cin>>l>>r;
	recur(l,r,0,0);
	cout<<res;
}