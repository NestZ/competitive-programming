#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	for(int i = 0;i < n;i++)cin >> a[i];
	for(int i = 0;i < n;i++)cin >> b[i];
	vector<vector<ll>> dp(2, vector<ll>(n, 0));
	dp[0][0] = a[0];
	dp[1][0] = b[0];
	if(n > 1){
		dp[0][1] = a[1] + b[0];
		dp[1][1] = b[1] + a[0];
		for(int i = 2;i < n;i++){
			dp[0][i] = max({dp[1][i - 1], dp[0][i - 2], dp[1][i - 2]}) + a[i];
			dp[1][i] = max({dp[0][i - 1], dp[1][i - 2], dp[0][i - 2]}) + b[i];
		}
	}
	cout << max(dp[0][n - 1], dp[1][n - 1]);
}
