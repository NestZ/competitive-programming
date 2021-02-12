#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const ll MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<char> arr(n);
	vector<vector<ll>> dp(n + 2, vector<ll>(n + 2));
	dp[1][1] = 1;
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 2;i <= n;i++){
		char lst = arr[i - 2];
		if(lst == 'f'){
			for(int j = n;j >= 1;j--){
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
		else{
			for(int j = n;j >= 1;j--){
				dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % MOD;
			}
		}
	}
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		ans = (ans + dp[n][i]) % MOD;
	}
	cout << ans << endl;
}
