#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<vector<ll>> g(200005);
vector<ll> s(200005, 0);
vector<ll> dep(200005, 0);
vector<ll> res(200005);

bool cmp(ll a, ll b){
	return a > b;
}

int dfs(ll n, ll f){
	dep[n] = dep[f] + 1;
	s[n] = 1;
	for(ll i : g[n]){
		if(i == f)continue;
		s[n] += dfs(i, n);
	}
	res[n] = s[n] - dep[n];
	return s[n];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;cin >> n >> k;
	for(ll i = 0;i < n - 1;i++){
		ll a, b;cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	nth_element(res.begin() + 1, res.begin() + n - k, res.begin() + n + 1, cmp);
	ll ans = 0;
	for(ll i = 1;i <= n - k;i++)ans += res[i];
	cout << ans;
}
