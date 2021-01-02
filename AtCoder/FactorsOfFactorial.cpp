#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	ll ans = 1;
	map<ll, ll> m;
	for(ll i = 1;i <= n;i++){
		ll num = i;
		for(ll j = 2;j * j <= num;j++){
			while(num % j == 0){
				m[j]++;
				num /= j;
			}
		}
		if(num > 1)m[num]++;
	}
	for(auto p : m){
		if(p.second > 0)
			ans = ans * (p.second + 1) % MOD;
	}
	cout << ans << endl;
}
