#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<vector<pair<int, int>>> g(100005);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;cin >> n >> m >> k;
	for(int i = 0;i < m;i++){
		int a, b, w;cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	set<int> s;
	for(int i = 0;i < k;i++){
		int t;cin >> t;
		s.insert(t);
	}
	int ans = INT_MAX;
	for(int i : s){
		for(pair<int, int> p : g[i]){
			if(s.count(p.first) == 0)ans = min(ans, p.second);
		}
	}
	if(ans == INT_MAX)cout << -1;
	else cout << ans;
}
