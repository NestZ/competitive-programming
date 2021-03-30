#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
const int mxc = 400010;
vector<vector<int>> g(mxc);
vector<int> scc(mxc, -1);
vector<bool> vis(mxc, false);
vector<bool> h(mxc, false);
vector<int> sz;

int dfs(int n, int cnt){
	vis[n] = true;
	scc[n] = cnt;
	int res = 1;
	for(auto adj : g[n]){
		if(!vis[adj])
			res += dfs(adj, cnt);
	}
	return res;
}

bool isTree(int n, int p){
	vis[n] = true;
	bool res = true;
	for(auto adj : g[n]){
		if(adj == p)continue;
		if(vis[adj])res = false;
		else res &= isTree(adj, n);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int ans = 0;
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		h[a] = h[b] = true;
	}
	int cnt = 0;
	for(int i = 1;i < mxc;i++){
		if(!h[i] || vis[i])continue;
		sz.push_back(dfs(i, cnt++));
	}
	fill(vis.begin(), vis.end(), false);
	for(int i = 1;i < mxc;i++){
		if(!h[i] || vis[i])continue;
		if(isTree(i, 0))ans += sz[scc[i]] - 1;
		else ans += sz[scc[i]];
	}
	cout << ans << endl;
}
