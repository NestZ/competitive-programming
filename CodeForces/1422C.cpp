#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	string s;cin >> s;
	ll n = s.length();
	const ll mod = 1e9 + 7;
	ll ans = 0;
	ll ten = 1;
	ll sum_right = 0;
	for(ll i = n - 1;i >= 0;i--){
		ll num = s[i] - '0';
		ll left = (i * (i + 1) / 2 % mod);
		ans = (ans + num * left % mod * ten % mod) % mod;
		ans = (ans + num * sum_right % mod) % mod;
		sum_right = (sum_right + (ten * (n - i)) % mod) % mod;
		ten = ten * 10 % mod;
	}
	cout << ans % mod;
}
