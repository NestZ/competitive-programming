#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
vector<vector<pair<int, ll>>> g(100010);
vector<bool> vis(100010, false);
vector<ll> dis(100010, INT64_MAX);

void dfs(int n, ll w){
	vis[n] = true;
	dis[n] = w;
	for(auto adj : g[n]){
		if(vis[adj.first])continue;
		dfs(adj.first, w + adj.second);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	for(int i = 0;i < n - 1;i++){
		int a, b, c;cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	int q, k;cin >> q >> k;
	dfs(k, 0);
	for(int i = 0;i < q;i++){
		int a, b;cin >> a >> b;
		cout << dis[a] + dis[b] << endl;
	}
}
