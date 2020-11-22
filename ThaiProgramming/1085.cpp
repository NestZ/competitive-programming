#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int ans = 0;
vector<vector<int>> warp(500001);
vector<bool> vis(500001, false);
void dfs(int n){
	ans = max(ans, n);
	vis[n] = true;
	for(auto i : warp[n]){
		if(!vis[i])
			dfs(i);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;cin >> n >> m >> k;
	vector<bool> rock(500001, false);
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		warp[a].push_back(b);
	}
	for(int i = 0;i < k;i++){
		int r;cin >> r;
		rock[r] = true;
	}
	for(int i = 1;i < n;i++){
		if(!rock[i]){
			warp[i].push_back(i + 1);
		}
	}
	dfs(1);
	if(ans == n)cout << 1 << endl;
	else cout << 0 << ' ' << ans << endl;
}
