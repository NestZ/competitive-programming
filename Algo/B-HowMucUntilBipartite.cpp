#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<vector<int>> g(100010);
vector<bool> vis(100010, false);
ll odd = 0;
ll even = 0;

void dfs(int n,  int d){
	vis[n] = true;
	if(d & 1)odd++;
	else even++;
	for(int adj : g[n]){
		if(!vis[adj])
			dfs(adj, d + 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i < n - 1;i++){
		int u, v;cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	cout << odd * even - n + 1 << endl;
}
