#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
struct node{
	int in = 0, re = 0;
};
map<int,int> M ,rM;
int cnt = 1, n,m;
vector<node> tree(N);
void up(int a, int b, int c){
	for(int i = a; i < cnt; i += (i & (-i))){
		if(b){
			tree[i].re += c;
		}else{
			tree[i].in += c;
		}
	}
}
pair<int,int> query(int a){
	int b = 0,c = 0;
	for(int i = a; i > 0; i -= (i & (-i))){
		b += tree[i].in;
		c += tree[i].re;
	}
	return {b,c};
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI3.INP","r",stdin);
	freopen("BAI3.OUT","w",stdout);
	cin>>n>>m;
	set<int> S;
	vector<pair<int,int>> adj(N);
	for(int i = 0; i < m; ++i){
		int a,b; cin>>a>>b;
		S.insert(a);
		S.insert(b);
		adj[i] = {a,b};
	}
	for(auto i : S){
		M[i] = cnt;
		rM[cnt] = i;
		++cnt;
	}
	for(int i = 0; i < m; ++i){
		int a = adj[i].first, b = adj[i].second;
		if(a <= b){
			up(M[a],0,1);
			up(M[b] + 1,0,-1);
			up(M[b],1,-1);
			up(M[b] + 1,1,1);
			// cout<<M[b] + 1;
		}else{
			up(M[a],0,1);
			up(M[b] + 1,0,-1);
			up(M[b],1,-1);
			up(1,0,1);
			up(M[b] + 1,1,1);
		}
	}
	int ans = 0, res = 0;
	for(int i = 1; i < cnt; ++i){
		pair<int,int> tmp = query(i);
		int a = tmp.first, b = tmp.second;
		int c = rM[i], d = rM[i + 1], e = d - (c + 1);
		if(i + 1 == cnt){
			if(ans < a){
				ans = a;
				res = 1;
				if(a + b == ans){
					res += (n - (c + 1) + 1);
				}
			}else if(ans == a){
				++res;
				if(a + b == ans){
					res += (n - (c + 1) + 1);
				}
			}
			break;
		}
		if(i == 1){
			if(ans < a){
				if(c != 1){
					ans = a;
					res = (c - 1 - 1 + 1);
				}
			}
		}
		// cout<<c<<"\n";
		if(ans < a){
			ans = a;
			res = 1;
			if(a + b == ans){
				res += e;
			}
		}else if(ans == a){
			++res;
			if(a + b == ans){
				res += e;
			}
		}
	}
	cout<<ans<<" "<<res;
}