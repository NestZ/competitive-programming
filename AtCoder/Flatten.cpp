#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const ll MOD = 1e9 + 7;

ll bin_pow(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b & 1ll)res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	vector<ll> arr(n);
	vector<ll> fac(1000010);
	for(int i = 0;i < n;i++)cin >> arr[i];
	ll lcm = 1;
	ll ans = 0;
	for(int i = 0;i < n;i++){
		ll tmp = arr[i];
		for(int j = 2;j * j <= arr[i];j++){
			ll cnt = 0;
			while(tmp % j == 0){
				tmp /= j;
				cnt++;
			}
			fac[j] = max(fac[j], cnt);
		}
		if(tmp > 1){
			fac[tmp] = max(fac[tmp], 1ll);
		}
	}
	for(int i = 0;i < 1000010;i++){
		if(fac[i] == 0)continue;
		lcm = lcm * bin_pow(i, fac[i]) % MOD;
	}
	for(int i = 0;i < n;i++){
		ans = (ans + lcm * bin_pow(arr[i], MOD - 2) % MOD) % MOD;
	}
	cout << ans << endl;
}
