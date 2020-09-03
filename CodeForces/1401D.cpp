#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1e9 + 7;
ll N = 100020;
ll n;
ll cnt = 0;
vector<pair<ll, ll>> g(2 * N);
vector<bool> vi(N, false);
vector<ll> w(N, 0);
vector<ll> pos(N, 0);

ll dfs(ll curr){
	ll d = 1;
	vi[curr] = true;
	for(ll i = pos[curr];i < pos[curr + 1];i++){
		if(!vi[g[i].second]){
			d += dfs(g[i].second);
		}
	}
	w[cnt] = d * (n - d);
	cnt++;
	return d;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		ll ans = 0;
		cin >> n;
		for(ll i = 0;i < n - 1;i++){
			cin >> g[i].first >> g[i].second;
			g[i + n - 1].first = g[i].second;
			g[i + n - 1].second = g[i].first;
		}
		sort(g.begin(), g.begin() + (2 * n - 2));
		for(ll i = 1;i < (2 * n - 2);i++){
			if(g[i].first > g[i - 1].first)pos[g[i].first] = i;
		}
		pos[n + 1] = (2 * n - 2);
		cnt = 0;
		dfs(1);
		assert(cnt == n);
		ll m;cin >> m;
		vector<ll> p(m);
		for(ll i = 0;i < m;i++)cin >> p[i];
		sort(p.rbegin(), p.rend());
		sort(w.rbegin(), w.rend());
		if(m < n){
			for(ll i = 0;i < n - 1;i++){
				ll num = (i >= ll(m) ? 1 : p[i]);
				ans = (ans + num * w[i]) % MOD;
			}
		}
		else{
			ans = 1;
			ll i;
			for(i = 0;i < m - n + 2;i++){
				ans = ans * p[i] % MOD;
			}
			ans = ans * w[0] % MOD;
			for(ll j = 1;j < n - 1;j++, i++){
				ans = (ans + p[i] * w[j]) % MOD;
			}
		}
		cout << ans << endl;
		for(ll i = 0;i < N;i++){
			w[i] = 0;
			vi[i] = false;
		}
	}
}
