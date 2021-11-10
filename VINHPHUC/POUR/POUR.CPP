#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	map<pair<int,int>,int> M;
	vector<int> A,B,V;
	int cnt = 0;
	node(vector<int> a, vector<int> b, vector<int> c) : A(a), B(b), V(c) {}
};
int check(vector<int> a, vector<int> b){
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if(a == b) return 1;
	return 0;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("POUR.INP","r",stdin);
	freopen("POUR.OUT","w",stdout);
	vector<int> A(4), B(4), V(4);
	for(int i = 1; i <= 3; ++i){
		cin>>V[i];
	}
	for(int i = 1; i <= 3; ++i){
		cin>>A[i];
	}
	for(int i = 1; i <= 3; ++i){
		cin>>B[i];
	}
	queue<node> q;
	q.push(node(A,B,V));
	while(!q.empty()){
		node a = q.front(); q.pop();
		if(check(a.A,a.B)){
			cout<<a.cnt;
			return 0;
		}
		for(int i = 1; i <= 3; ++i){
			for(int j = 1; j <= 3; ++j){
				if(i != j && !a.M[{i,j}]){
					node b = a;
					b.M[{i,j}]++;
					int tmp = min(b.V[j] - b.A[j], b.A[i]);
					b.A[j] += tmp;
					b.A[i] -= tmp;
					b.cnt++;
					q.push(b);
				}
			}
		}
	}
	cout<<-1;
}