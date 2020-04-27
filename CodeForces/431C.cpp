#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, d;cin >> n >> k >> d;
	int dp[101][2];
	for(int i = 0;i <= 100;i++)
		for(int j = 0;j < 2;j++)
			dp[i][j] = 0;
	dp[0][0] = 1;
	dp[0][1] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= k;j++){
			if(i - j < 0)break;
			if(j < d){
				dp[i][0] += dp[i - j][0];
				dp[i][1] += dp[i - j][1];
				dp[i][0] %= MOD;
				dp[i][1] %= MOD;
			}
			else{
				dp[i][1] += dp[i - j][0];
				dp[i][1] %= MOD;
				dp[i][1] += dp[i - j][1];
				dp[i][1] %= MOD;
			}
		}
	}
	cout << dp[n][1];
}
