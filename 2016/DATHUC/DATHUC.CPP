#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6;
int n;
double x; 
vector<double> pre(M),adj(M);
void st(){
	double ans = 1;
	pre[0] = 1;
	for(int i = 1; i <= n; ++i){
		ans *= x;
		pre[i] = ans;
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("DATHUC.INP","r",stdin);
	freopen("DATHUC.OUT","w",stdout);
	cin>>n>>x;
	for(int i = 0; i <= n; ++i){
		cin>>adj[i];
	}
	st();
	double ans = 0;
	for(int i = 0; i <= n; ++i){
		ans += (pre[i] * adj[i]);
	}
	cout<<fixed<<setprecision(2)<<ans;

}