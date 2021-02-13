#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const ll MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	ll ans = 0;
	vector<ll> arr(n);
	vector<ll> zero(70);
	vector<ll> one(70);
	for(ll i = 0;i < n;i++)cin >> arr[i];
	for(ll k = 0;k <= 60;k++){
		for(ll i = 0;i < n;i++){
			if(arr[i] & (1ll << k))one[k]++;
			else zero[k]++;
		}
		ll cur = (1ll << k) % MOD;
		cur = (cur * one[k]) % MOD;
		cur = (cur * zero[k]) % MOD;
		ans = (ans + cur) % MOD;
	}
	cout << ans << endl;
}
