#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<vector<ll>> g(100005);
vector<bool> v(100005, false);
vector<ll> c(100005);

ll dfs(ll n, ll &p){
	v[n] = true;
	for(ll a : g[n]){
		if(!v[a])dfs(a, p);
	}
	p = min(p, c[n]);
	return p;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;cin >> n >> m;
	for(ll i = 0;i < n;i++){
		ll t;cin >> t;
		c[i + 1] = t;
	}
	for(ll i = 0;i < m;i++){
		ll a, b;cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ll ans = 0;
	for(ll i = 1;i <= n;i++){
		ll t = INT64_MAX;
		if(!v[i])ans += dfs(i, t);
	}
	cout << ans;
}
