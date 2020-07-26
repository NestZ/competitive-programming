#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	for(int q = 0;q < t;q++){
		int n;cin >> n;
		ll ans = 0;
		map<ll, ll> m;
		vector<pair<ll, ll>> arr;
		for(int i = 0;i < n;i++){
			ll a, b;cin >> a >> b;
			arr.push_back({a, b});
		}
		sort(arr.begin(), arr.end());
		for(int i = 0;i < n;i++){
			ll a = arr[i].first;
			ll b = arr[i].second;
			m[a + b] = max(m[a + b], m[a] + b);
			m[a] = max(b + m[a - b], m[a]);
		}
		for(pair<ll, ll> p : m){
			ans = max(ans, p.second);
		}
		cout << "Case #" << q + 1 << ": " << ans << endl;
	}
}
