#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, k;cin >> t >> k;
	const ll m = 1e9 + 7;
	vector<ll> dp(100005, 0);
	vector<ll> sum(100005, 0);
	dp[0] = 1;
	sum[0] = 1;
	for(int i = 1;i <= 100000;i++){
		if(i - k < 0)dp[i] += dp[i - 1] % m;
		else dp[i] += (dp[i - 1] + dp[i - k]) % m;
		sum[i] += (sum[i - 1] + dp[i]) % m;
	}
	for(int i = 0;i < t;i++){
		int a, b;cin >> a >> b;
		cout << (sum[b] - sum[a - 1] + m) % m << endl;
	}
}
