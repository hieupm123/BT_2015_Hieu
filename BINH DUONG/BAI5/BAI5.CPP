#include<bits/stdc++.h>
using namespace std;
#define int long long
struct P{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	void in(int a, int b, int c, int d){
		x1 = a; y1 = b; x2 = c; y2 = d;
	}
};
vector<int> X, Y;
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   freopen("BAI5.INP","r",stdin);
   freopen("BAI5.OUT","w",stdout);
	int n; cin>>n;
	vector<P> adj(n);
	for(int i = 0; i < n; ++i){
		int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
		X.push_back(x1); Y.push_back(y1);
		X.push_back(x2); Y.push_back(y2);
		adj[i].in(x1,y1,x2,y2);
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	int ans = 0;
	for(int i = 1; i < (int)X.size(); ++i){
		for(int j = 1; j < (int)Y.size(); ++j){
			int x1 = X[i], y1 = Y[j], x2 = X[i - 1], y2 = Y[j - 1];
			for(int k = 0; k < (int)adj.size(); ++k){
				if(adj[k].x1 <= x2 && adj[k].y1 <= y2 && adj[k].x2 >= x1 && adj[k].y2 >= y1){
					ans = ans + (x1 - x2) * (y1 - y2);
					break;
				}
			}
		}
	}
	cout<<ans;
}