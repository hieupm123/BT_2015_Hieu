#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 100;
stack<int> adj[N];
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI3.INP","r",stdin);
	// freopen("BAI3.OUT","w",stdout);
	int n,k, cnt = 1; cin>>n>>k;
	vector<int> res(N,k);
	vector<int> A(n);
	for(int i = 0; i < n; ++i){
		cin>>A[i];
	}
	vector<int> tmp = A;
	sort(tmp.begin(),tmp.end());
	map<int,int> M;
	for(int i = 0; i < (int)tmp.size(); ++i){
		if(!M[tmp[i]]){
			M[tmp[i]] = cnt;
			++cnt;
		}
		tmp[i] = M[tmp[i]];
	}
	reverse(tmp.begin(),tmp.end());
	cnt = 1;
	for(int i = 0; i < (int)tmp.size(); ++i){
		A[i] = M[A[i]];
		if(i != 0 && i % k == 0){
			++cnt;
		}
		adj[tmp[i]].push(cnt);
	}
	M.clear();
	int ans = 0;
	for(int i = (int)A.size() - 1; i >= 0; --i){
		while(res[cnt] == 0 && cnt > 0){
			--cnt;
		}
		int b = adj[A[i]].top(); adj[A[i]].pop();
		// cout<<b<<" ";
		if(b != cnt){
			++ans;
			cout<<A[i]<<" "<<b<<"\n";
		}
		res[b]--;
	}
	// cout<<ans;
	
}