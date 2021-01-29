#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
vector<vector<pair<int, int>>> g(100010);
vector<bool> vis(100010, false);
vector<int> ans(100010, 0);

void dfs(int n, int cur_paint){
	vis[n] = true;
	ans[n] = cur_paint;
	for(auto p : g[n]){
		if(vis[p.first])continue;
		int paint = cur_paint;
		if(p.second & 1){
			if(cur_paint == 0)paint = 1;
			else paint = 0;
		}
		dfs(p.first, paint);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	for(int i = 0;i < n - 1;i++){
		int a, b, w;cin >> a >> b >> w;
		g[a].emplace_back(b, w);
		g[b].emplace_back(a, w);
	}
	dfs(1, 0);
	for(int i = 1;i <= n;i++)
		cout << ans[i] << endl;
}
