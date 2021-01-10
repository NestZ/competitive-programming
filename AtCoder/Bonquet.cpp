#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1e9 + 7;

ll bin_pow(ll b, ll e){
	ll res = 1;
	while(e > 0){
		if(e & 1)res = res * b % MOD;
		b = b * b % MOD;
		e >>= 1;
	}
	return res;
}

ll choose(ll n, ll k){
	ll x = 1, y = 1;
	for(ll i = n;i >= n - k + 1;i--){
		x = x * i % MOD;
	}
	for(ll i = k;i >= 1;i--){
		y = y * i % MOD;
	}
	y = bin_pow(y, MOD - 2);
	return x * y % MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, a, b;cin >> n >> a >> b;
	ll p = bin_pow(2ll, n) - 1;
	p += MOD;
	p -= choose(n, a);
	p += MOD;
	p -= choose(n, b);
	cout << p % MOD << endl;
}
