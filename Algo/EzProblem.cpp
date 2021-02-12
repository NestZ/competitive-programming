#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
typedef long long int ll;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n;cin >> n;
	string s;cin >> s;
	vector<ll> c(n);
	vector<vector<ll>> dp(4, vector<ll>(n + 1));
	for(int i = 0;i < n;i++)cin >> c[i];
	for(int i = 1;i <= n;i++){
		char cur = s[i - 1];
		ll cost = c[i - 1];
		for(int j = 0;j < 4;j++){
			dp[j][i] = dp[j][i - 1];
		}
		if(cur == 'h'){
			dp[0][i] = cost + dp[0][i - 1];
		}
		else if(cur == 'a'){
			dp[1][i] = min(dp[0][i - 1], cost + dp[1][i - 1]);
		}
		else if(cur == 'r'){
			dp[2][i] = min(dp[1][i - 1], cost + dp[2][i - 1]);
		}
		else if(cur == 'd'){
			dp[3][i] = min(dp[2][i - 1], cost + dp[3][i - 1]);
		}
	}
	cout << dp[3][n] << endl;
}
