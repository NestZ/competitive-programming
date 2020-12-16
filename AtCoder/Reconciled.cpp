#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll MOD = 1e9 + 7;

ll fac(ll n){
	ll ans = 1;
	while(n > 1){
		ans *= n;
		ans %= MOD;
		n--;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;cin >> n >> m;
	ll ans = 0;
	if(abs(n - m) == 1)ans = fac(n) * fac(m);
	else if(abs(n - m) == 0)ans = fac(n) * fac(m) % MOD * 2;
	cout << ans % MOD << endl;
}
