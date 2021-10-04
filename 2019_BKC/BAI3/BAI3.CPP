#include<bits/stdc++.h>
using namespace std;
#define int long long
string add(string a, string b){
	while((int)b.size() < (int)a.size()){
		b = '0' + b;
	}
	int po = 0;
	string res = "";
	for(int i = (int)b.size() - 1; i >= 0; --i){
		int c = b[i] - '0' + a[i] - '0' + po;
		po = c / 10;
		int tmp = c % 10;
		res = (char)(tmp + '0') + res;
	}
	if(po > 0) res = (char)(po + '0') + res;
	return res;
}
string sub(string a, string b){
	while((int)b.size() < (int)a.size()){
		b = '0' + b;
	}
	int po = 0;
	string res = "";
	for(int i = (int)b.size() - 1; i >= 0; --i){
		int c = (a[i] - '0') - (b[i] - '0') - po;
		if(c < 0){
			c += 10;
			po = 1;
		}else{
			po = 0;
		}
		res = char(c % 10 + '0') + res;
	}
	while((int)res.size() > 0 && res[0] == '0') res.erase(0,1);
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
int upper(string a, string b){
	if((int)a.size() < (int)b.size()){
		return 0;
	}else if((int)a.size() == (int)b.size()){
		if(a < b){
			return 0;
		}
	}
	return 1;
}
string div(string a, string b){
	string tmp = "", res = "";
	// cout<<a<<" "<<b<<"\n";
	bool check = 0;
	for(int i = 0; i < (int)a.size(); ++i){
		tmp += a[i];
		if(i == (int)a.size() - 1 && !upper(tmp,b)){
			check = 1;
		}
		// if(upper(tmp,b) || tmp == "0"){
			int t = 0; string tmpop = "";
			for(int j = 0; j <= 9; ++j){
				string op = mul(b,to_string(j));
				if(upper(tmp,op)){
					tmpop = op;
					t = j;
				}
			}
			// cout<<t<<"\n";
			tmp = sub(tmp,tmpop);
			if(tmp == "0"){
				tmp = "";
			}
			res += to_string(t);
		// }
	}
	// if(check){
	// 	res += '0';
	// }
	while(res.size() > 1 && res[0] == '0') res.erase(0,1);
	return res;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("BAI3.INP","r",stdin);
	freopen("BAI3.OUT","w",stdout);
	string a,b,c; cin>>a>>c>>b;
	string ans = "";
	if(c == "cong"){
		ans = add(a,b);
	}else if(c == "tru"){
		ans = sub(a,b);
	}else{
		ans = div(a,b);
	}
	string res = "";
	if(ans == "0"){
		cout<<0;
		return 0;
	}
	// cout<<div("201601","2");
	while(ans != "0"){
	// for(int i = 0; i < 50; ++i){
		// cout<<ans<<"\n";
		int a = ans[(int)ans.size() - 1] - '0';
		(a % 2) ? res = '1' + res : res = '0' + res;
		ans = div(ans,"2");
	// }
	}
	cout<<res;
}