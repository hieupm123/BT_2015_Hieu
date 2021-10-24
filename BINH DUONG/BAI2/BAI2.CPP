#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   string res;
   getline(cin,res);
   string ans = "", tmp = "";
   for(int i = 0; i < (int)res.size(); ++i){
      if(res[i] != ' '){
         tmp += res[i];
      }else{
         if(tmp != ""){
            ans = tmp;
            tmp = "";
         }
      }
   }
   if(tmp != "") ans = tmp;
   cout<<ans;
}