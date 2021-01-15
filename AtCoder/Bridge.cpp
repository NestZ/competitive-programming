#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<vector<int>> g(55);
vector<bool> vis(55, false);
pair<int, int> cut;

bool is_cut(int a, int b){
	if(a == cut.first && b == cut.second)return true;
	if(a == cut.second && b == cut.first)return true;
	return false;
}

int dfs(int n){
	vis[n] = true;
	int cnt = 1;
	for(int adj : g[n]){
		if(!vis[adj] && !is_cut(n, adj))
			cnt += dfs(adj);
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;cin >> n >> m;
	int ans = 0;
	vector<pair<int, int>> e;
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		e.emplace_back(a, b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 0;i < m;i++){
		cut = e[i];
		if(dfs(1) != n)ans++;
		vis = vector<bool>(55, false);
	}
	cout << ans << endl;
}
