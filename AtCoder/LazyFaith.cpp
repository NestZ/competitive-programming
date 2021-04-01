#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a, b, q;cin >> a >> b >> q;
	vector<ll> s(a);
	vector<ll> t(b);
	for(int i = 0;i < a;i++)cin >> s[i];
	for(int i = 0;i < b;i++)cin >> t[i];
	for(int i = 0;i < q;i++){
		ll x;cin >> x;
		auto sl = upper_bound(s.begin(), s.end(), x);
		if(sl == s.begin())sl = s.end();
		else sl--;
		auto sr = upper_bound(s.begin(), s.end(), x - 1);
		auto tl = upper_bound(t.begin(), t.end(), x);
		if(tl == t.begin())tl = t.end();
		else tl--;
		auto tr = upper_bound(t.begin(), t.end(), x - 1);
		ll csl = (sl == s.end() ? 1e15 : s[sl - s.begin()]);
		ll csr = (sr == s.end() ? 1e15 : s[sr - s.begin()]);
		ll ctl = (tl == t.end() ? 1e15 : t[tl - t.begin()]);
		ll ctr = (tr == t.end() ? 1e15 : t[tr - t.begin()]);
		cout << min({max({x, csl, ctl}) - min({x, csl, ctl}),
						abs(csl - x) + abs(ctr - csl),
						abs(csr - x) + abs(ctl - csr),
						abs(ctl - x) + abs(csr - ctl),
						abs(ctr - x) + abs(csl - ctr),
						max({x, csr, ctr}) - min({x, csr, ctr})}) << endl;
	}
}
