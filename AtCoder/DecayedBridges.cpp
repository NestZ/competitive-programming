#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
vector<ll> parent(100010);
vector<ll> sz(100010, 1);

ll find(ll x){
	while(x != parent[x])x = parent[x];
	return x;
}

bool same(ll a, ll b){
	return find(a) == find(b);
}

void unite(ll a, ll b){
	a = find(a);
	b = find(b);
	if(sz[a] < sz[b])swap(a, b);
	sz[a] += sz[b];
	sz[b] = 0;
	parent[b] = a;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m;cin >> n >> m;
	ll ans = n * (n - 1) / 2;
	vector<pair<ll, ll>> arr;
	vector<ll> res;
	for(int i = 1;i <= n;i++)parent[i] = i;
	for(int i = 0;i < m;i++){
		ll a, b;cin >> a >> b;
		arr.push_back({a, b});
	}
	for(int i = m - 1;i >= 0;i--){
		res.push_back(ans);
		ll sa = find(arr[i].first);
		ll sb = find(arr[i].second);
		ll sza = sz[sa];
		ll szb = sz[sb];
		if(!same(sa, sb)){
			unite(sa, sb);
			ans -= sza * szb;
		}
	}
	reverse(res.begin(), res.end());
	for(ll i : res)cout << i << endl;
}
