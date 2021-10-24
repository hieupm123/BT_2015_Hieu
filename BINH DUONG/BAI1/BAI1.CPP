#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int a; cin>>a;
   vector<int> adj = {1,6,11,16};
   map<int,int> M = {{5,8000},{10,10000},{15, 14000},{20,20000}};
   int ans = 0, cnt = 0;
   for(map<int,int>::iterator it = M.begin(); it !=  M.end(); ++it){
      int b = (*it).first, c = (*it).second;
      if(a > (b - adj[cnt] + 1)){
         ans += c * (b - adj[cnt] + 1);
         a -= (b - adj[cnt] + 1);
         ++cnt;
      }else{
         ans += a * c;
         a = 0;
         break;
      }
   }
   if(a > 0){
      ans += a * 30000;
   }
   cout<<ans + (ans / 10);
}