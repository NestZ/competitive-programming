#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const ll MOD = 1e9 + 7;
vector<ll> fac_mod(100010);
vector<ll> fac_inv(100010);

ll bin_pow(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b & 1)res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

ll binom(ll n, ll k){
	if(k > n)return 0ll;
	if(k > n - k)k = n - k;
	return fac_mod[n] * fac_inv[k] % MOD * fac_inv[n - k] % MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, k;cin >> n >> k;
	ll sum_mx = 0, sum_mn = 0;
	vector<ll> arr(n);
	for(ll i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	fac_mod[0] = 1;
	fac_inv[0] = 1;
	for(ll i = 1;i <= n;i++){
		fac_mod[i] = fac_mod[i - 1] * i % MOD;
		fac_inv[i] = bin_pow(fac_mod[i], MOD - 2);
	}
	for(ll i = 0;i < n;i++){
		sum_mx = (sum_mx + arr[i] * binom(i, k - 1) % MOD) % MOD;
		sum_mn = (sum_mn + arr[i] * binom(n - i - 1, k - 1) % MOD) % MOD;
	}
	cout << (sum_mx - sum_mn + MOD) % MOD << endl;
}
