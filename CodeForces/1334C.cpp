#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll t;cin >> t;
	while(t--){
		ll n;cin >> n;
		vector<ll> a(n);
		vector<ll> b(n);
		for(ll i = 0;i < n;i++)cin >> a[i] >> b[i];
		ll sum = 0;
		for(ll i = 0;i < n;i++)sum += max(0LL, a[i] - b[(i + n - 1) % n]);
		ll ans = INT64_MAX;
		for(ll i = 0;i < n;i++){
			ans = min(ans, sum + a[i] - max(0LL, a[i] - b[(i + n - 1) % n]));
		}
		cout << ans << endl;
	}
}
