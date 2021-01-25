#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<vector<ll>> dp(3, vector<ll>(n + 1, 0));
	for(int i = 0;i < n;i++)cin >> a[i];
	for(int i = 0;i < n;i++)cin >> b[i];
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[0][1] = a[0];
	dp[1][1] = b[0];
	for(int i = 2;i <= n;i++){
		ll nc = max(dp[0][i - 1], dp[1][i - 1]);	
		ll ca = max(a[i - 1] + dp[1][i - 1], a[i - 1] + dp[2][i - 1]);
		ll cb = max(b[i - 1] + dp[0][i - 1], b[i - 1] + dp[2][i - 1]);
		dp[0][i] = ca;
		dp[1][i] = cb;
		dp[2][i] = nc;
	}
	cout << max({dp[0][n], dp[1][n], dp[2][n]}) << endl;
}
