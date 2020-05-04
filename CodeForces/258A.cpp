#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;cin >> s;
	int n = s.length();
	bool b = false;
	string ans = "";
	for(char c : s){
		if(c == '1')ans += c;
		else if(!b)b = true;
		else ans += c;
	}
	if(ans.length() == n)ans = ans.substr(1, n - 1);
	cout << ans;
}
