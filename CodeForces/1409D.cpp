#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll dig(ll n){
	ll res = 0;
	while(n > 0){
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll t;cin >> t;
	while(t--){
		ll n, s;cin >> n >> s;
		ll temp = n;
		ll ans = 0;
		ll curr = 0;
		while(dig(n) > s){
			ll last = temp % 10;
			ll diff = 10 - last;
			n += diff * ll(pow(10ll, curr));
			ans += diff * ll(pow(10ll, curr));
			curr++;
			temp = n;
			temp /= ll(pow(10ll, curr));
		}
		cout << ans << endl;
	}
}
