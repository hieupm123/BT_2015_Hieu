#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mx = 1e6 + 100;
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0); 
   int a;
   map<int, int> M; 
   vector<int> check(Mx);
   int cnt = 1;
   while(cin>>a){
      if(a == 0){
         break;
      }
      M[a]++;
      if(!check[a]){
         check[a] = cnt;
         ++cnt;
      }
   }
   int ans = 0, id = 0;
   for(map<int,int>::iterator it = M.begin(); it != M.end(); ++it){
      int b = (*it).first, c = (*it).second;
      if(c > ans){
         ans = c;
         id = b;
      }else if(c == ans && check[id] < check[b]){
         id = b;
      }
   }
   cout<<id<<" "<<ans;
}