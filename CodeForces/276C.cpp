#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, t;cin >> n >> t;
	vector<ll> arr(n);
	for(ll i = 0;i < n;i++)cin >> arr[i];
	vector<ll> f(n + 2);
	vector<ll> cnt(n + 2);
	for(ll i = 0;i < t;i++){
		ll a, b;cin >> a >> b;
		f[a]++;
		f[b + 1]--;
	}
	for(ll i = 1;i <= n;i++){
		cnt[i] = f[i] + cnt[i - 1];
	}
	sort(arr.rbegin(), arr.rend());
	sort(cnt.rbegin(), cnt.rend());
	ll ans = 0;
	for(int i = 0;i < n;i++){
		ans += arr[i] * cnt[i];
	}
	cout << ans;
}
