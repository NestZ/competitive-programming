#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;cin >> n;
	ll cur = 0;
	map<ll, ll> m;
	m[cur] = 1;
	ll ans = 0;
	for(ll i = 0;i < n;i++){
		ll num;cin >> num;
		cur += num;
		if(m[cur] != 0)ans += m[cur];
		m[cur]++;
	}
	cout << ans << endl;
}
