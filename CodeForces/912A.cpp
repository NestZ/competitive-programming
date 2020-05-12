#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;cin >> a >> b;
	ll x, y, z;cin >> x >> y >> z;
	ll wa = x * 2 + y;
	ll wb = y + 3 * z;
	ll ans = max(0LL, wa - a) + max(0LL, wb - b);
	cout << ans;
}
