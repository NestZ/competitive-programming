#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, k;cin >> n >> k;
	ll ans = 0;
	for(ll a = 1;a <= n;a++){
		ll b = k - (a % k);
		if(b == 0 || b > n)continue;
		ll c = k - (b % k);
		if(c == 0 || c > n || (a + c) % k != 0)continue;
		ans += ((n - b) / k + 1) * ((n - c) / k + 1);
	}
	cout << ans << endl;
}
