#include<bits/stdc++.h>
using namespace std;
#define int long long
string add(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}
string mul(string a, string b)
{
    string res="";
    int n=a.length();
    int m=b.length();
    int len=n+m-1;
    int carry=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m && i-j>=1)
            {
                int a1=a[j]-48;
                int b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
            tmp+=carry;
            carry=tmp/10;
            res=(char)(tmp%10 + 48)+res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    return res;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("TRIACU.INP","r",stdin);
	freopen("TRIACU.OUT","w",stdout);
	int n; cin>>n;
	vector<pair<int,int>> adj(n);
	for(int i = 0; i < n; ++i){
		int a,b; cin>>a>>b;
		adj[i] = make_pair(a * a,b);
	}
	sort(adj.begin(), adj.end());
	vector<int> A(n + 100),pre(n + 100),fs(n + 100);
	for(int i = 1; i <= n; ++i){
		A[i] = adj[i - 1].first;
		pre[i] = pre[i - 1] + adj[i - 1].second;
		fs[i] = adj[i - 1].second;
	}
	string ans = "";
	for(int i = 1; i <= n - 2; ++i){
		for(int j = i + 1; j <= n - 1; ++j){
			int L = j + 1, R = n;
			int tmp = 0;
			while(L <= R){
				int mid = (L + R) / 2;
				if(A[i] + A[j] > A[mid]){
					L = mid + 1;
					tmp = mid;
				}else{
					R = mid - 1;
				}
			}
			if(tmp){
				ans = add(ans,mul(mul(to_string(fs[i]),to_string(fs[j])),to_string(pre[tmp] - pre[j])));
			}
		}
	}
	ans == "" ? cout<<0 : cout<<ans;
}