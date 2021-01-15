#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	set<pair<ll, ll>> s;
	vector<pair<ll, ll>> arr;
	for(ll i = 0;i < n;i++){
		ll x, y;cin >> x >> y;
		arr.emplace_back(x, y);
	}
	sort(arr.begin(), arr.end());
	for(ll i = 0;i < n - 1;i++){
		for(ll j = i + 1;j < n;j++){
			ll dx = arr[j].first - arr[i].first;
			ll dy = arr[j].second - arr[i].second;
			s.emplace(dx, dy);
		}
	}
	ll ans = n;
	for(auto cur : s){
		ll p = cur.first;
		ll q = cur.second;
		ll rnd = 0;
		vector<bool> pick(n, false);
		for(ll i = 0;i < n;i++){
			if(pick[i])continue;
			else rnd++;
			pick[i] = true;
			auto last = arr[i];
			for(ll j = i + 1;j < n;j++){
				if(pick[j])continue;
				if(last.first + p == arr[j].first &&
						last.second + q == arr[j].second){
					pick[j] = true;
					last = arr[j];
				}
			}
		}
		ans = min(ans, rnd);
	}
	cout << ans << endl;
}
