#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const int INF = 1e9;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	for(int q = 1;q <= t;q++){
		int ans = 0;
		int x, y;cin >> x >> y;
		string s;cin >> s;
		int n = s.length();
		//c = 0, j = 1
		vector<vector<int>> dp(2, vector<int>(n + 1));
		for(int i = 1;i <= n;i++){
			char cur = s[i - 1];
			if(cur == '?'){
				dp[0][i] = min(dp[1][i - 1] + y, dp[0][i - 1]);
				dp[1][i] = min(dp[0][i - 1] + x, dp[1][i - 1]);
			}
			else if(cur == 'C'){
				//choose c
				dp[0][i] = min(dp[1][i - 1] + y, dp[0][i - 1]);
				//choose j
				dp[1][i] = INF;
			}
			else{
				//choose c
				dp[0][i] = INF;
				//choose j
				dp[1][i] = min(dp[0][i - 1] + x, dp[1][i - 1]);
			}
		}
		if(s[n - 1] == '?')ans = min(dp[0][n], dp[1][n]);
		else if(s[n - 1] == 'C')ans = dp[0][n];
		else ans = dp[1][n];
		cout << "Case #" << q << ": " << ans << endl;
	}
}
