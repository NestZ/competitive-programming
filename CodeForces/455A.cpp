#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n;cin >> n;
	map<ll, ll> m;
	for(ll i = 0;i < n;i++){
		ll t;cin >> t;
		m[t]++;
	}
	vector<ll> dp(100010);
	dp[0] = 0;
	dp[1] = m[1];
	for(ll i = 2;i <= 100005;i++){
		dp[i] = max(dp[i - 1], i * m[i] + dp[i - 2]);
	}
	cout << dp[100000];
}
