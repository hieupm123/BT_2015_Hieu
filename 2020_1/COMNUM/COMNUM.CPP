#include<bits/stdc++.h>
using namespace std;
#define int long long
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
string maxx(string a, string b){
	if(a == b){
		return b;
	}
	if((int)a.size() > (int)b.size()){
		return a;
	}else if((int)a.size() < (int)b.size()){
		return b;
	}
	for(int i = 0; i < (int)a.size(); ++i){
		if(a[i] > b[i]){
			return a;
		}else if(a[i] < b[i]){
			return b;
		}
	}
	return b;
}
string modpow(string a, int b){
	string ans = "1";
	while(b){
		if(b & 1) ans = mul(ans,a);
		a = mul(a,a);
		b /= 2;
	}
	return ans;
}
string check(string a, string b){
	string ans = "0", tmp = "1";
	int ok = 0;
	for(int i = 0; i < (int)a.size(); ++i){
		if(i == 0){
			if(a[i] == b[i]){
				ok = 1;
			}else{
				string s = ""; s += b[i] - 1;
				ans = maxx(ans,mul(mul(tmp,s),modpow("9",((int)b.size() - 1 - i))));
			}
		}else{
			if(b[i] != '0' && i != (int)a.size() - 1){
				string s = ""; s += b[i] - 1;
				if(!ok){
					ans = maxx(ans,mul(mul(tmp,s),modpow("9",((int)b.size() - 1 - i))));
				}else{
					if(b[i] != a[i]){
						ans = maxx(ans,mul(mul(tmp,s),modpow("9",((int)b.size() - 1 - i))));
						ok = 0;
					}
				}
			}
		}
		string s = ""; s += b[i];
		tmp = mul(tmp,s);
	}
	ans = maxx(ans,tmp);
	return ans;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("COMNUM.INP","r",stdin);
	freopen("COMNUM.OUT","w",stdout);
	string L, R; cin>>L>>R;
	string ans = "0";
	if((int)R.size() > (int)L.size()){
		string anst = "0";
		if(R[0] == '1'){
			anst = modpow("9",(int)R.size() - 1);
		}else{
			string temp = "1";
			for(int i = 0; i < R.size(); ++i){
				if(R[i] != '0' && i != (int)R.size() - 1){
					string s = ""; s += R[i] - 1;
					anst = maxx(anst,mul(mul(temp,s),modpow("9",((int)R.size() - 1 - i))));
				}
				string s = ""; s += R[i];
				temp = mul(temp,s);
			}
			anst = maxx(anst,temp);
		}
		cout<<anst;
	}else{
		ans = maxx(ans,check(L,R));
		cout<<ans;
	}
}