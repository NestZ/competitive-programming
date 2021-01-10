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
	return x * bin_pow(y, MOD - 2) % MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll x, y;cin >> x >> y;
	ll curx = 0, cury = 0;
	ll down = 0;
	ll up = 0;
	bool valid = false;
	while(curx <= x){
		if(y - cury == 2 * (x - curx)){
			up = x - curx;
			valid = true;
			break;
		}
		curx += 2;
		cury += 1;
		down++;
	}
	if(!valid)cout << 0;
	else{
		ll n = down + up;
		ll k = down;
		cout << choose(n, k);
	}
	cout << endl;
}
