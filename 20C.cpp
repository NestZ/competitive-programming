#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	ll n, m;cin >> n >> m;
	priority_queue<pair<ll, ll>> q;
	vector<vector<pair<ll, ll>>> g(n + 1);
	vector<ll> f(n + 1, -1);
	vector<ll> dis(n + 1, INT64_MAX);
	for(int i = 0;i < m;i++){
		ll v, u, d;cin >> v >> u >> d;
		g[v].push_back({-d, u});
		g[u].push_back({-d, v});
	}
	q.push({0, 1});
	while(!q.empty()){
		pair<ll, ll> curr = q.top();
		q.pop();
		ll u = curr.second;
		for(pair<ll, ll> p : g[u]){
			if(dis[p.second] > dis[u] - p.first){
				dis[p.second] = dis[u] - p.first;
				f[p.second] = u;
				q.push(p);
			}
		}
	}
	vector<ll> ans;
	if(dis[n] == INT64_MAX)cout << -1;
	else{
		ll curr = n;
		while(curr != 1){
			ans.push_back(curr);
			curr = f[curr];
		}
		ans.push_back(1);
		reverse(ans.begin(), ans.end());
		for(ll i : ans)cout << i << ' ';
	}
}
