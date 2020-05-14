#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	unordered_map<ll, ll> x;
	unordered_map<ll, ll> y;
	unordered_map<pair<ll, ll>, ll> m;
	ll ans = 0;
	for(int i = 0;i < n;i++){
		ll a, b;cin >> a >> b;
		ans += x[a]++;
		ans += y[b]++;
		ans -= m[{a, b}]++;
	}
	cout << ans;
}
