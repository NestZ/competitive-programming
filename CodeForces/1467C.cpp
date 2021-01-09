#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a, b, c;cin >> a >> b >> c;
	ll suma = 0, sumb = 0, sumc = 0;
	vector<ll> mn(3, INT64_MAX);
	for(ll i = 0;i < a;i++){
		ll num;cin >> num;
		mn[0] = min(mn[0], num);
		suma += num;
	}
	for(ll i = 0;i < b;i++){
		ll num;cin >> num;
		mn[1] = min(mn[1], num);
		sumb += num;
	}
	for(ll i = 0;i < c;i++){
		ll num;cin >> num;
		mn[2] = min(mn[2], num);
		sumc += num;
	}
	sort(mn.begin(), mn.end());
	ll sum = suma + sumb + sumc;
	cout << max(sum - 2 * min({suma, sumb, sumc}),
			sum - 2 * (mn[0] + mn[1])) << endl;
}
