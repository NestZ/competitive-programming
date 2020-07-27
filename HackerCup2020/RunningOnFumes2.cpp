#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define MAX 5000005

vector<vector<ll>> g(MAX);
vector<ll> mn(MAX, INT64_MAX);
vector<ll> ci(MAX);
vector<bool> v(MAX, false);
queue<pair<ll, ll>> q;
ll m;

void dfs(ll curr, ll cost, ll dep){
	if(dep > m)return;	
	v[curr] = true;
	if(mn[curr] > cost){
		mn[curr] = cost;
		q.push(make_pair(curr, mn[curr]));
	}
	for(ll adj : g[curr]){
		if(!v[adj])
			dfs(adj, cost, dep + 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ll t;cin >> t;
	for(ll c = 0;c < t;c++){
		fill(v.begin(), v.end(), false);
		fill(mn.begin(), mn.end(), INT64_MAX);
		fill(g.begin(), g.end(), vector<ll>());
		ll n, a, b;cin >> n >> m >> a >> b;
		mn[a] = 0;
		for(ll i = 0;i < n;i++){
			ll s, e;cin >> s >> e;
			if(s > 0){
				g[s].push_back(i + 1);
				g[i + 1].push_back(s);
			}
			if(e == 0)ci[i + 1] = INT64_MAX;
			else ci[i + 1] = e;
		}
		dfs(a, 0, 0);
		while(!q.empty()){
			pair<ll, ll> p = q.front();
			q.pop();
			if(ci[p.first] == INT64_MAX || mn[p.first] == INT64_MAX || mn[p.first] < p.second)continue;
			fill(v.begin(), v.end(), false);
			dfs(p.first, mn[p.first] + ci[p.first], 0);
		}
		mn[b] = (mn[b] == INT64_MAX ? -1 : mn[b]);
		cout << "Case #" << c + 1 << ": " << mn[b] << endl;
	}
}
