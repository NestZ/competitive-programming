#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const int MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;cin >> s;
	int n = s.length();
	vector<vector<int>> dp(n + 1, vector<int>(13));
	dp[0][0] = 1;
	for(int i = 1;i <= n;i++){
		int cur = s[i - 1] - '0';
		for(int j = 0;j <= 9;j++){
			if(s[i - 1] == '?')cur = j;
			else if(cur != j)continue;
			for(int k = 0;k <= 12;k++){
				int rem = (k * 10 + cur) % 13;
				dp[i][rem] = (dp[i][rem] + dp[i - 1][k]) % MOD;
			}
		}
	}
	cout << dp[n][5] << endl;
}
