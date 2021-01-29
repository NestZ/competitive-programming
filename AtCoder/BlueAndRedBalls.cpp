#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const ll MOD = 1e9 + 7;

ll bin_pow(ll a, ll b){
	ll ans = 1;
	while(b > 0){
		if(b & 1)ans = ans * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return ans;
}

ll bin_cof(ll n, ll k){
	k = max(k, n - k);
	ll x = 1;
	ll y = 1;
	for(ll i = n;i > k;i--){
		x = x * i % MOD;
	}
	for(ll i = n - k;i >= 1;i--){
		y = y * i % MOD;
	}
	return x * bin_pow(y, MOD - 2) % MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, k;cin >> n >> k;
	ll r = n - k;
	for(int i = 1;i <= k;i++){
		if(r < i - 1)cout << 0;
		else{
			ll ans = bin_cof(k - 1, i - 1);
			ans = ans * bin_cof(r + 1, i) % MOD;
			cout << ans;
		}
		cout << endl;
	}
}
