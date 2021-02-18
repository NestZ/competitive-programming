#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
ll mx = 200000;
vector<ll> sum(mx, 0);
vector<ll> cnt(mx, 0);

void add_cnt(ll idx, ll delta){
	for(;idx <= mx;idx += idx & -idx)
		cnt[idx] += delta;
}

ll sum_cnt(ll idx){
	ll res = 0;
	for(;idx > 0;idx -= idx & -idx)
		res += cnt[idx];
	return res;
}

void add_sum(ll idx, ll delta){
	for(;idx <= mx;idx += idx & -idx)
		sum[idx] += delta;
}

ll sum_sum(ll idx){
	ll res = 0;
	for(;idx > 0;idx -= idx & -idx)
		res += sum[idx];
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	ll ans = 0;
	vector<pair<ll, ll>> arr;
	for(ll i = 0;i < n;i++){
		ll a, b;cin >> a >> b;
		arr.emplace_back(a, b);
		add_cnt(b, 1);
		add_sum(b, a);
	}
	sort(arr.begin(), arr.end());
	for(ll i = 0;i < n;i++){
		ll cur_cnt = sum_cnt(arr[i].second) - 1;
		ans += arr[i].first * cur_cnt;
		ans += sum_sum(arr[i].second) - arr[i].first;
		add_cnt(arr[i].second, -1);
		add_sum(arr[i].second, -arr[i].first);
	}
	cout << ans << endl;
}
