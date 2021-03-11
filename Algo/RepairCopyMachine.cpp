#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const ll MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;cin >> s;
	int n = s.length();
	vector<ll> dp(n + 1, 1);
	if(s.find_first_of("mw") != string::npos)cout << 0;
	else{
		for(int i = 2;i <= n;i++){
			dp[i] = dp[i - 1];
			if((s[i - 1] == 'n' && s[i - 2] == 'n') ||
					(s[i - 1] == 'u' && s[i - 2] == 'u')){
				dp[i] = (dp[i] + dp[i - 2]) % MOD;
			}
		}
		cout << dp[n];
	}
	cout << endl;
}
