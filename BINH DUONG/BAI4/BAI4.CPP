#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mx = 1e6 + 100;
struct node{
   int cnt = 0, r = 0;
};
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   freopen("BAI4.INP","r",stdin);
   freopen("BAI4.OUT","w",stdout);
   int n; cin>>n;
   string s; cin>>s; s = '#' + s;
   vector<node> dp(Mx); 
   int ans = 0, check = 0;
   for(int i = 1; i <= n; ++i){
      if(dp[i - 1].r){
         dp[i].r = dp[i - 1].r + 1;
         if(s[i] == 'L'){
            (dp[i].r % 2 != 0) ? ans += dp[i].r - 1 : ans += dp[i].r;
            dp[i].r = 0;
         }else if(s[i] == 'R'){
            ans += dp[i].r - 1;
            dp[i].r = 1;
         }
      }else{
         if(s[i] == '.'){
            dp[i].cnt = dp[i - 1].cnt + 1;
         }else if(s[i] == 'L'){
            ans += dp[i - 1].cnt + 1;
         }else{
            dp[i].r++;
         }
      }
   }
   ans += dp[n].r;
   cout<<n - ans;
}