#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
vector<vector<int>> g(100010);
vector<bool> vis(100010, false);

void dfs(int n){
	vis[n] = true;
	for(auto adj : g[n]){
		if(!vis[adj])
			dfs(adj);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;cin >> n >> m;
	int ans = 0;
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 1;i <= n;i++){
		if(vis[i])continue;
		else{
			ans++;
			dfs(i);
		}
	}
	cout << ans - 1 << endl;
}
