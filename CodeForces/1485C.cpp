#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll t;cin >> t;
	while(t--){
		ll a, b;cin >> a >> b;
		ll ans = 0;
		for(ll i = 1;i * i <= a;i++){
			ans += max(0ll, min(b, a / i - 1) - i);
		}
		cout << ans << endl;
	}
}
