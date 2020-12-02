#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll q, h, s, d;cin >> q >> h >> s >> d;
	ll n;cin >> n;
	ll minh = min(h, q * 2);
	ll mins = min(s, minh * 2);
	ll mind = min(d, mins * 2);
	ll ans = n / 2 * mind;
	if(n & 1)ans += mins;
	cout << ans << endl;
}
