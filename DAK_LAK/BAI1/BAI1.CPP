#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6, inf = 1e18;
struct node{
	int pre = -inf, sum = 0;
};
vector<int> adj(M);
vector<node> tree(M);
void build(int l, int r, int cnt){
	if(l == r){
		tree[cnt].sum = adj[l];
		tree[cnt].pre = adj[l];
		return;
	}
	int mid = (l + r) / 2;
	build(l,mid,2 * cnt);
	build(mid + 1,r,2 * cnt + 1);
	tree[cnt].sum = tree[2 * cnt].sum + tree[2 * cnt + 1].sum;
	tree[cnt].pre = max(tree[2 * cnt].pre,tree[2 * cnt].sum + tree[2 * cnt + 1].pre); 
}
node query(int l, int r, int cnt, int a, int b){
	if(a > r || b < l){
		node tmp;
		// cout<<tmp.sum<<"\n";
		return tmp;
	}
	if(a <= l && b >= r){
		return tree[cnt];
	}
	node L, R, ans;
	int mid = (l + r) / 2;
	L = query(l,mid,2 * cnt,a,b);
	R = query(mid + 1,r,2 * cnt + 1,a,b);
	ans.sum = L.sum + R.sum;
	ans.pre = max(L.pre,L.sum + R.pre);
	return ans;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI1.INP","r",stdin);
	freopen("BAI1.OUT","w",stdout);
	int n; cin>>n;
	for(int i = 1; i <= n; ++i){
		cin>>adj[i];
		// cout<<adj[i]<<" ";
	}
	// cout<<"\n";
	build(1,n,1);
	int ans = -inf;
	// for(int i = 1; i <= 24; ++i){
	// 	cout<<tree[i].sum<<" ";
	// }
	// cout<<"\n";
	for(int i = 1; i <= n; ++i){
		ans = max(query(1,n,1,i,n).pre,ans);
		// cout<<i<<" "<<n<<" "<<query(1,n,1,i,n).sum<<"\n";
	}
	cout<<ans;

}