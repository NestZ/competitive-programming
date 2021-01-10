#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll h, n;cin >> h >> n;
	vector<ll> dp(10010, INT64_MAX);
	vector<pair<ll, ll>> arr;
	for(int i = 0;i < n;i++){
		ll a, b;cin >> a >> b;
		arr.emplace_back(a, b);
		if(a >= h)dp[h] = min(dp[h], b);
		else dp[a] = min(dp[a], b);
	}
	for(int i = 0;i < 10010;i++){
		if(dp[i] == INT64_MAX)continue;
		for(auto p : arr){
			if(i + p.first >= h)
				dp[h] = min(dp[h], dp[i] + p.second);
			else 
				dp[i + p.first] = min(dp[i + p.first], dp[i] + p.second);
		}
	}
	cout << dp[h] << endl;
}
